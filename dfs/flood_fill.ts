function floodFill(image: number[][], sr: number, sc: number, color: number): number[][] {
    if(image[sr][sc]!==color)
        dfs(image,sr,sc,color,image[sr][sc])
    return image
};

function dfs(image: number[][], r: number, c: number, color: number,orginalColor:number):void{
    if(r===image.length || c===image[0].length || r===-1 || c===-1 )
        return 
    if(image[r][c]!==orginalColor)
        return
    image[r][c]=color
    dfs(image,r+1,c,color,orginalColor)
    dfs(image,r-1,c,color,orginalColor)
    dfs(image,r,c+1,color,orginalColor)
    dfs(image,r,c-1,color,orginalColor)
}


console.log(floodFill([[1,1,1],[1,1,0],[1,0,1]],1,1,2))