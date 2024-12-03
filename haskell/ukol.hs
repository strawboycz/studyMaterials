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

getNeighbours :: (Num a, Num b) => (a, b) -> [(a, b)]
getNeighbours (r1, c1) = [(r1 - 1, c1), (r1 + 1, c1), (r1, c1 - 1), (r1, c1 + 1)]

solve :: (Num n, Num a, Num b, Eq a, Eq b) => [(a, b, n)] -> [(a, b)] -> n
solve [] _ = 0
solve ((r1, c1, price):toSolve) nowEmpty =
    let
        allNeighbours = [n | n <- getNeighbours (r1, c1), elem n nowEmpty]
        newEmpty = nowEmpty \\ allNeighbours
    in (r1, c1, price) :
       solve (toSolve ++ [(r, c, price + 1) | (r, c) <- allNeighbours]) newEmpty

solveMaze :: Num a => [[Char]] -> Int
solveMaze maze =
    let
        indexes = concat [[(ri, ci, ch) | (ci, ch) <- zip [0..] line] | (ri, line) <- zip [0..] maze]
        (sr, sc) = head [(ri, ci) | (ri, ci, ch) <- indexes, ch == 's']
        (er, ec) = head [(ri, ci) | (ri, ci, ch) <- indexes, ch == 'e']
        empty = [(ri, ci) | (ri, ci, ch) <- indexes, ch == '.' || ch == 'e']
        solved = solve [(sr, sc, 0)] empty
    in if head [price | (r, c, price) <- solved, r == er, c == ec] == m
       then m
       else -1

    
