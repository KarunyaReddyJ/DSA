use clap::{App, Arg, SubCommand};

fn main() {
    let matches = App::new("My CLI App")
                    .version("1.0")
                    .author("Your Name")
                    .about("Advanced CLI application in Rust")
                    .subcommand(SubCommand::with_name("add")
                                .about("Add two numbers")
                                .arg(Arg::with_name("first")
                                    .help("First number")
                                    .required(true)
                                    .index(1))
                                .arg(Arg::with_name("second")
                                    .help("Second number")
                                    .required(true)
                                    .index(2)))
                    .get_matches();

    // Handle subcommands and options
    match matches.subcommand() {
        ("add", Some(sub_m)) => {
            let num1: i32 = sub_m.value_of("first").unwrap().parse().unwrap();
            let num2: i32 = sub_m.value_of("second").unwrap().parse().unwrap();
            let result = num1 + num2;
            println!("Result: {}", result);
        }
        _ => {
            // Handle other commands or provide usage instructions
            println!("{}", matches.usage());
        }
    }
}
