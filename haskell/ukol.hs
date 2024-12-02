type Maze = [String]

printMaze :: Maze -> IO ()
printMaze x = putStr (concat (map (++"\n") x))

sample1 :: Maze
sample1 = ["*********",
           "* *   * *",
           "* * * * *",
           "* * * * *",
           "*   *   *",
           "******* *",
           "        *",
           "*********"]
sample2 :: Maze
sample2 = ["       ",
           "       ",
           "  ***  ",
           "  ***  ",
           "  ***  ",
           "       ",
           "       "]
sample3 :: Maze
sample3 = ["  * *  ",
           " ##### ",
           "  ***  ",
           "  * *  ",
           "  ***  ",
           "     * ",
           "       "]
sample4 :: Maze
sample4 = ["*********",
           "*s*   *e*",
           "* *   * *",
           "* *   * *",
           "*       *",
           "******* *",
           "        *",
           "*********"]
arrow :: Maze
arrow = [ "....#....",
          "...###...",
          "..#.#.#..",
          ".#..#..#.",
          "....#....",
          "....#....",
          "....#####"]

above :: Maze -> Maze -> Maze
above maze1 maze2 = maze1 ++ maze2

sideBySide :: Maze -> Maze -> Maze
sideBySide [] [] = []
sideBySide [] a = a
sideBySide a [] = a
sideBySide (a:as) (b:bs) = (a ++ b) : (sideBySide as bs) 

rotateOneR :: String -> Maze
rotateOneR [] = []
rotateOneR (char:chars) = [char : ""] ++ rotateOneR chars

rotateOneL :: String -> Maze
rotateOneL [] = []
rotateOneL (char:chars) = rotateOneL chars ++ [char : ""]

rotateR :: Maze -> Maze
rotateR [] = []
rotateR maze = map (reverse) (temp [] maze)
    where 
        temp output [] = output
        temp output (row:rows) = temp (sideBySide output (rotateOneR row)) rows 

rotateL :: Maze -> Maze
rotateL [] = []
rotateL maze = temp [] maze
    where 
        temp output [] = output
        temp output (row:rows) = temp (sideBySide output (rotateOneL row)) rows 


getFromMaze :: Maze -> (Int, Int) -> Char
getFromMaze maze (x,y) = (maze !! x) !! y

putIntoMaze :: Maze -> [(Int, Int, Char)] -> Maze
putIntoMaze maze [] = maze
putIntoMaze maze ((x,y,char):triplets) = let 
    rowsBefore = take (x) maze
    currentRow = take y (maze !! x) ++ [char] ++ drop y (maze !! x)
    rowsAfter = drop (x + 1) maze
    in putIntoMaze (rowsBefore ++ [currentRow] ++ rowsAfter) triplets

getPart :: Maze -> (Int,Int) -> (Int,Int) -> Maze
getPart maze (x,y) (height,width) = take height (drop x [take width (drop y row) | row <- maze])

solveMaze :: Maze -> Int
solveMaze maze = let
    
