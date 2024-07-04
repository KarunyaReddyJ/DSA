import tkinter as tk
from tkinter import messagebox
from tkinter import ttk
import requests
import mysql.connector
from datetime import date, timedelta
import matplotlib.pyplot as plt
API_ENDPOINT = 'https://alfa-leetcode-api.onrender.com/karunya_kumar/'
# MySQL connection configuration
mysql_config = {
    'host': 'localhost',
    'user': 'root',
    'password': 'Karunya@27',
    'database': 'leetcode_rankings',
}

def fetch_rankings():
    # Example function to fetch rankings from API
    response = requests.get(API_ENDPOINT)
    if response.status_code == 200:
        return response.json()
    else:
        return None

def save_to_mysql(rankings):
    # Connect to MySQL database
    try:
        conn = mysql.connector.connect(**mysql_config)
        cursor = conn.cursor()

        # Example query: Inserting into a table named 'daily_rankings'
        query = "INSERT INTO daily_rankings (ranking, date) VALUES (%s, %s)"
        today = date.today()
        data = (rankings, today)
        cursor.execute(query, data)

        conn.commit()
        print("Rankings saved successfully!")
    except mysql.connector.Error as error:
        print(f"Error: {error}")
    finally:
        if conn.is_connected():
            cursor.close()
            conn.close()

def fetch_and_save():
    # Fetch today's rankings from API
    rankings = fetch_rankings()

    if rankings:
        # Save rankings to MySQL
        save_to_mysql(rankings['ranking'])
        messagebox.showinfo("Success", "Rankings saved successfully!")
    else:
        messagebox.showerror("Error", "Failed to fetch rankings from the API.")

def plot_rankings():
    try:
        conn = mysql.connector.connect(**mysql_config)
        cursor = conn.cursor()

        # Example query to retrieve rankings and dates
        query = "SELECT date, ranking FROM daily_rankings ORDER BY date"
        cursor.execute(query)

        dates = []
        rankings = []
        for row in cursor.fetchall():
            dates.append(row[0])
            rankings.append(row[1])

        # Close connection
        cursor.close()
        conn.close()

        # Plotting using matplotlib
        plt.figure(figsize=(10, 6))
        plt.plot(dates, rankings, marker='o', linestyle='-', color='b')
        plt.title('LeetCode Rankings Over Time')
        plt.xlabel('Date')
        plt.ylabel('Ranking')
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()

    except mysql.connector.Error as error:
        print(f"Error: {error}")
        messagebox.showerror("Error", f"Failed to plot rankings: {error}")

def main():
    fetch_and_save()

    # Create a simple GUI
    root = tk.Tk()
    root.title("Daily LeetCode Rankings")

    def refresh():
        fetch_and_save()

    def show_graph():
        plot_rankings()

    btn_refresh = ttk.Button(root, text="Refresh Rankings", command=refresh)
    btn_refresh.pack(pady=10)

    btn_graph = ttk.Button(root, text="Show Graph", command=show_graph)
    btn_graph.pack(pady=10)

    root.mainloop()

if __name__ == "__main__":
    main()
