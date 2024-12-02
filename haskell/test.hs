

import Data.Char

countDigits x = helper x 0
            where 
            helper 0 i = i
            helper x i = helper (div x 10) (i+1)

concatNumbers x y = x * 10^(countDigits y) + y


insert :: [a] -> a -> [a]
insert [] y = [y]
insert (x:xs) y = x : y : xs



f :: [a] -> a -> [a] 
f x y = [y] ++ x

listNumbers n s m = take n [s,s+m .. ]


listNumbers' :: Int -> Int -> Int -> [Int]
listNumbers' n s m | n == 0 = []
                   | otherwise = listNumbers' (n-1) s m ++ [s+n*m - m]


listOdd :: Int -> Int -> [Int]
listOdd a b | a == b = a : []
            | mod a 2 == 0 = listOdd (a+1) b ++ []
            | mod b 2 /= 0 = listOdd a (b-2) ++ [b]
            | otherwise = listOdd a (b-1)

length' :: [a] -> Int
length' (x:xs) = help (x:xs) 0
    where 
    help [] i = i
    help (x:xs) i = help xs (i+1)

sumIt :: [Int] -> Int
sumIt [] = 0
sumIt (x:xs) = sum xs + x 

getHead' :: [a] -> a
getHead' (x:xs) = x

getLast :: [a] -> a
getLast [a] = a
getLast (x:xs) = getLast (xs)


take' :: Int -> [a] -> [a]
take' 0 _ = []
take' _ [] = []
take' n (x:xs) = x: take' (n-1) xs

drop' :: Int -> [a] -> [a]
drop' 0 (x:xs) = (x:xs)
drop' n (x:xs) = drop' (n-1) xs 

minimum' :: Ord a => [a] -> a -- Is this right?
minimum' (x:xs) = help (xs) x
    where
        help [] a = a
        help (x:xs) a | x < a = help (xs) x
                      | otherwise  = help xs a


divisors :: Int -> [Int]
divisors n = help n
    where 
        help 0 = []
        help x | mod n x == 0 = x:help (x-1)
               | otherwise = help (x-1)

oddList :: Int -> Int -> [Int]
oddList a b = filter(\x -> x`mod` 2 /= 0) [a..b]

removeAllUpper :: String -> String
removeAllUpper s = filter(isLower) s 


union :: Eq a => [a] -> [a] -> [a]
union a b = (filter(\x -> not (x `elem` b)) a ) ++ b

intersection :: Eq a => [a] -> [a] -> [a]
intersection a b = filter(\x -> x `elem` b) a


getCharacters :: String -> [Char]
getCharacters s = temp s []
    where 
        temp [] l = l
        temp (x:xs) l | x `elem` l = temp xs l
                      | otherwise = temp xs (l ++ [x])

countChar :: Char -> String -> Int
countChar a s = temp a s 0
    where
        temp _ [] count = count
        temp a (x:xs) count | a == x = temp a xs (count+1)
                            | otherwise = temp a xs count


countThem :: String -> [(Char, Int)]
countThem s = temp (getCharacters s)
    where 
        temp [] = []
        temp (x:xs) = [(x,countChar x s)] ++ temp xs

type Pic = [String]
pp :: Pic -> IO ()
pp x = putStr (concat (map (++"\n") x))
pic :: Pic
pic = [ "....#....",
        "...###...",
        "..#.#.#..",
        ".#..#..#.",
        "....#....",
        "....#....",
        "....#####"]

reverse' :: String -> String
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]


flipV :: Pic -> Pic
flipV p = map(\x -> reverse' x) p

flipH :: Pic -> Pic
flipH [] = []
flipH (x:xs) = flipH xs ++ [x]


above :: Pic -> Pic -> Pic
above a b = a ++ b

sideBySide :: Pic -> Pic -> Pic
sideBySide (a:as) (b:bs) = [a ++ b] ++ sideBySide as bs

removeOne :: Eq a => a -> [a] -> [a]
removeOne a (l:ls) = temp a (l:ls) [] 
    where 
        temp _ [] _  = []
        temp x (y:ys) rest | x == y = rest ++ ys
                           | otherwise = temp x ys ([y] ++ rest)


not' :: Bool -> Bool
not' True = False
not' False = True
infixl 5 `not'`

and' :: Bool -> Bool -> Bool
and' True True = True
and' _ _ = False
infixl 4 `and'`

or' :: Bool -> Bool -> Bool
or' True _ = True
or' _ True = True
or' _ _ = False
infixl 3 `or'`

nand' :: Bool -> Bool -> Bool
nand' a b = not' (a `and'` b)
infixl 4 `nand'`

xor' :: Bool -> Bool -> Bool
xor' False True = True
xor' True False = True
xor' _ _ = False
infixl 4 `xor'`

impl' :: Bool -> Bool -> Bool
impl' True False = False
impl' _ _ = True
infixl 2 `impl'` 

equ' :: Bool -> Bool -> Bool
equ' x y = x == y
infixl 7 `equ'` 

table :: (Bool -> Bool -> Bool) -> IO ()
table expr = putStr getResults
    where
        getResults = concatMap (\(x,y) -> (show x) ++ " " ++ (show y) ++ "\t|" ++ " " ++ (show (x `expr` y)) ++ "\n") [(a, b)| a <- [True,False], b <- [True,False]]

splitByElement :: Eq a => [a] -> a -> [a]
splitByElement list delimiter = temp list delimiter []
    where 
        output x y = takeWhile (/=x) y
        rest x y = dropWhile (/=x) y
        temp [] _ _ = []
        temp a b c = temp (rest b a) b (c ++ (output b a))


---data Entity = Point {x :: Double, y :: Double}
            --- Circle {center :: Entity, radius :: Int}
    -- Container {entites :: [Entity]} deriving Show

---entity :: Entity
---entity = Container [(Point 1 3),(Circle (Point 2 5) 15)]



{-
    data Component = TextBox {name :: String, text :: String}
               | Button {name :: String, value :: String}
               | Container {name :: String, children :: [Component]} deriving Show

gui :: Component
gui = Container "misa" [
    Container "capek" [
        Button "ahoj_btn" "ahoj",
        Button "ahoj_btn" "ahoj"
    ],
    Container "capek2" [
        Button "ahoj_btn" "ahoj",
        Button "ahoj_btn" "ahoj"]]



countButtons :: Component -> Int
countButtons (Button a b) = 1
countButtons (TextBox c d) = 0
countButtons (Container x y) = sum (map countButtons y)
-}


-- vsechny ukoly 1 strasne ez imo, funguje to + - stejne


    

data Component = TextBox {name :: String, text :: String}
               | Button {name :: String, value :: String}
               | Container {name :: String, children :: [Component]} deriving Show

-- tady je ten basic shit
gui :: Component
gui = Container "misa" [
    Container "capek" [
        Button "ahoj_btn" "ahoj",
        Button "ahoj_btn" "ahoj",
        TextBox "tb" "nevim"
    ],
    Container "capek2" [
        Button "ahoj_btn" "ahoj",
        Button "ahoj_btn" "ahoj"],
    Container "capek 3" []
        ]

tb :: Component
tb = TextBox "tb" "nevim"


-- zadani 2

{-
data Entity = Point Double Double 
            | Circle (Double, Double) Double 
            | Container [Entity]
-}

countButtons :: Component -> Int
countButtons (Button a b) = 1
countButtons (TextBox c d) = 0
countButtons (Container x y) = sum (map countButtons y)

addElement :: Component -> Component -> String -> Component
addElement (Container name children) toAdd containerName | name == containerName = (Container name (children ++ [toAdd]))
                                                         | otherwise = Container name (map (\x -> addElement x toAdd containerName) children)
addElement component _ _ = component


-- zadani 4
data Attribute = Attribute String String

data Tag = Tag String [Attribute] [Tag]

data HTMLDocument = HTMLDocument [Tag]

dokument :: HTMLDocument 
dokument = HTMLDocument [(Tag "<head>" [Attribute "nevim" "ahoj"] []),(Tag "<body>" [Attribute "nevim" "ahoj"] [(Tag "<h1>" [Attribute "text" "ahoj"] [])])]


listButtonNames :: Component -> [String]
listButtonNames (Button name _) = [name]
listButtonNames (Container name children) = concat (map listButtonNames children)

changeText :: Component -> String -> String -> Component
changeText (TextBox name oldStr) token newStr | name == token = (TextBox name newStr)
                                              | otherwise = (TextBox name oldStr)
changeText (Container name children) token newStr = Container name (map (\x -> changeText x token newStr) children)
changeText component _ _ = component                                      


-- zadani 5

listAllButtons :: Component -> [Component]
listAllButtons (Button name value) = [Button name value]
listAllButtons (Container name children) = concat (map listAllButtons children)
listAllButtons component = []

removeAllButtons :: Component -> Component -- zla funkce kamo nevim jak jinak vyresit nez takto
removeAllButtons (TextBox name value) = TextBox name value
removeAllButtons (Container name children) = Container name (map removeAllButtons (filter(isNotButton) children))
    where 
        isNotButton (Button _ _ )= False
        isNotButton _ = True

-- zadani 6

listAllNames :: Component -> [String]
listAllNames (Button name _ ) = [name]
listAllNames (TextBox name _ ) = [name]
listAllNames (Container name children ) = [name] ++ concat (map listAllNames children)

removeElements :: Component -> [String] -> Component -- opet docela bolestive
removeElements (Container name children ) names =  Container name (map (`removeElements` names) (filter (hasntName) children))
    where 
        hasntName (Button name _ ) = name `notElem` names
        hasntName (TextBox name _ ) = name `notElem` names
        hasntName (Container name _ ) = name `notElem` names
removeElements component _ = component

-- na fotce neni cislo

countAllComponents :: Component -> Int
countAllComponents (Button _ _) = 1
countAllComponents (TextBox _ _) = 1
countAllComponents (Container _ children) = sum (map (countAllComponents) children) + 1

removeEmptyContainers :: Component -> Component
removeEmptyContainers (Container name children) = Container name (map (removeEmptyContainers) (filter isNotEmpty children))
    where 
        isNotEmpty (Container _ children) | length children > 0 = True
                                          | otherwise  = False
        isNotEmpty component = True
removeEmptyContainers component = component
