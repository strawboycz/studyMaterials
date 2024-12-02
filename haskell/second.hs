import Data.Traversable (for)
import System.Win32 (xBUTTON1, aCCESS_SYSTEM_SECURITY, SECURITY_ATTRIBUTES (bInheritHandle))
import Distribution.Simple.HaskellSuite (getLanguages)
import Data.Char
import Data.ByteString (split)
fact :: Int -> Int
fact 0 = 1
fact n = n * fact (n-1)

fact2 :: Int -> Int
fact2 n | n==0 = 1
        | otherwise = n * fact2 (n - 1)


fact3 :: Int -> Int
fact3 n = if n == 0 then 1 else n*fact3 (n-1)


fib :: Int -> Int
fib 0 = 1
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

fib2 :: Int -> Int
fib2 n = pomocna 1 1 0 where
    pomocna a b i | (i == n) = a
                  | otherwise = pomocna b (a+b) (i+1)




leapyear :: Int -> Bool
leapyear n | (mod n 400) == 0 = True
           | ((mod n 100) > 0 && (mod n 4) == 0) = True
           | otherwise = False


mult :: (Eq t1, Num t1, Num t2) => t2 -> t1 -> t2 -> t2
mult a 0 suma = suma
mult a b suma = mult a (b-1) (suma + a)

mult2 :: (Eq t1, Num t1, Num t2, Num (t2 -> t2)) => t2 -> t1 -> t2 -> t2
mult2 a 0 = 0
mult2 a b = mult a (b - 1)


gcd' a b | (a == b) = a
         | (a > b) = gcd' (a-b) b
         | (a < b) = gcd' a (b-a)


isPrime a = help a (a-1)
    where help a 1 = True
          help a i | mod a i == 0 = False
                   | otherwise = help a (i-1)

isPrime' a = help a ( floor ( (sqrt (fromIntegral a))))
    where help a 1 = True
          help a i | mod a i == 0 = False
                   | otherwise = help a (i-1)

sumList :: [Int] -> Int
sumList [] = 0
sumList (x:xs) = x + sumList (xs)


getHead (x:xs) = x

getLast :: [a] -> a
getLast [] = error "empty list"
getLast [x] = x
getLast (x:xs) = getLast (xs)


isElement :: Eq a => a -> [a] -> Bool
isElement a [] = False
isElement a (x:xs) | a == x = True
                   | otherwise = isElement a xs

getTail :: [a] -> [a]
getTail [] = error "empty list"
getTail (x:xs) = xs

getInit :: [a] -> [a]
getInit [] = error "empty list"
getInit [_] = []
getInit (x:xs) = x : getInit xs

combine :: [a] -> [a] -> [a]
combine [] [] = []
combine [] y = y
combine (x:xs) y = x : combine (xs) y

combine2 :: [a] -> [a] -> [a]
combine2 [] y = y
combine2 x y = x ++ y




reverse' :: [a] -> [a]
reverse' [] = []
reverse' [x] = [x]
reverse' (x:xs) = reverse' xs ++ [x]

scalar :: [Int] -> [Int] -> Int
scalar [] [] = error "error"
scalar [x] [y] = x * y
scalar (x:xs) (y:ys) = (x * y) + scalar xs ys

take' :: Int -> [a] -> [a]
take' n [] = []
take' n (x:xs) | n == 0 = (x:xs)
               | otherwise = take' (n-1) xs

drop' :: Int -> [a] -> [a]
drop' n [] = []
drop' n (x:xs) | n == 0 = []
               | otherwise = x : drop' (n-1) xs

minimum' :: Ord a => [a] -> a -- Is this right?
minimum' (x:xs) = help (xs) x
    where
        help [] a = a
        help (x:xs) a | x < a = help xs x
                      | otherwise = help xs a


divisors :: Int -> [Int]
divisors x = help x x
    where
        help x a | a == 1 = [a]
                 | mod x a == 0 = help x (a-1) ++ [a]
                 | otherwise  = help x (a-1)

listNumbers ::  Int -> Int -> Int -> [Int]
listNumbers _ _ 0 = error "Division by 0"
listNumbers a b m | mod a m /= 0 = listNumbers (a+1) b m
              | mod b m /= 0 = listNumbers a (b-1) m
              | otherwise = [a,a+m .. b]

zipThem:: [a] -> [b] -> [(a,b)]
zipThem _ [] = error "Empty list"
zipThem [] _ = error "Empty list"
zipThem [a] [b] = [(a,b)]
zipThem (a:as) (b:bs) = (a,b) : zipThem as bs

zloun :: [a] -> [b] -> [(a,b)]
zloun _ [] = error "empty list"
zloun [] _ = error "empty list"
zloun as bs = help as bs (length as) (length bs)
    where
        help as bs la lb | la == 1 && lb == 0 = []
                         | lb > 0 = help as bs la (lb-1) ++ [(as !! (la - 1) , bs !! (lb - 1) )]
                         | otherwise = help as bs (la-1) (length bs)

dotProduct :: [a] -> [b] -> [(a,b)]
dotProduct xs ys = [(x,y) | x <- xs, y <- ys]

-- [ x^2 | x <- [1,2]] = [1,4] -  generator seznamu
-- map (^2) [1,2] = [1,4] - funkce map
-- filter (<10) [1,40,20] = 1  - filter
-- map (\x -> x^2) [1,2] = [1,4] - literally lambda
-- fliter (\x < 10) [1,40,20] = 1 - literally lambda

allToUpperGen :: String -> String
allToUpperGen xs = [toUpper x | x <- xs]

allToUpperMap :: String -> String
allToUpperMap xs = map toUpper xs

oddList :: Int -> Int -> [Int]
oddList a b = filter (\x -> (mod x 2) /= 0) [a .. b]

removeAllUpper :: String -> String
removeAllUpper s = filter (\x -> isLower x) s

union :: Eq a => [a] -> [a] -> [a]
union a b = a ++  filter (\x -> not (x `elem` a)) b

intersection :: Eq a => [a] -> [a] -> [a]
intersection a b = filter (\x -> x `elem` b) a


unique :: String -> String
unique [] = []
unique (x:xs) = x : unique (filter (/= x) xs)

countThem :: String -> [(Char, Int)]
countThem s = map (\x -> help x s) (unique s)
    where help c s = (c, length (filter (==c) s))

data CNumber = ComplexNumber Float Float |
               Real Float
               deriving (Show,Eq) -- deriving - dědičnost


complexAdd :: CNumber -> CNumber -> CNumber
complexAdd (ComplexNumber a b) (ComplexNumber c d) = ComplexNumber (a+b) (c+d)
complexAdd (Real a) (Real b) = ComplexNumber (a+b) 0

data Expr = Num Int
          | Add Expr Expr
          | Sub Expr Expr
          | Mul Expr Expr
          | Div Expr Expr
          | Var Char
           deriving (Eq)

eval :: Expr -> Int
eval (Num a) = a
eval (Add a b) = eval a + eval b
eval (Sub a b) = eval a - eval b
eval (Mul a b) = eval a * eval b
eval (Div a b) | b == Num 0 = error "Devision by 0"
               | otherwise = eval a `div` eval b

-- dalsi prikaldy na https://homel.vsb.cz/~vas218/docs/fpr/data_types.pdf

showExpr :: Expr -> String
showExpr (Num a) = show a
showExpr (Add a b) =  "(" ++ showExpr a ++ "+" ++ showExpr b ++ ")"
showExpr (Sub a b) = "(" ++ showExpr a ++ "-" ++ showExpr b ++ ")"
showExpr (Mul a b) = "(" ++ showExpr a ++ "*" ++ showExpr b ++ ")"
showExpr (Div a b) = "(" ++ showExpr a ++ "/" ++ showExpr b ++ ")"
showExpr (Var a) = [a]

instance (Show Expr) where
    show :: Expr -> String
    show = showExpr


deriv :: Expr-> Char -> Expr
deriv (Num a) _ = Num 0
deriv (Add a b) c = Add (deriv a c) (deriv b c)
deriv (Mul a b) c = Add (Mul (deriv a c) (deriv b c)) (Mul (deriv a c) (deriv b c))
deriv (Var a) b = if a == b then (Num 1) else (Num 0)
-- showExpr (Mul (Add (Num 1) (Mul (Num 2) (Var 'x'))) (Mul (Num 3) (Var 'x')))


--DATA TYPES + BINARY TREES

data Tree a = Branch a (Tree a) (Tree a) 
            | Leaf a 
            deriving (Show,Eq)

getTree :: Tree Int
getTree = Branch 5 (Branch 3 (Leaf 2) (Leaf 4)) (Leaf 6) 


treeSum :: Num a => Tree a -> a 
treeSum (Leaf value) = value
treeSum (Branch a lTree rTree)= a + treeSum lTree + treeSum rTree

treeToList :: Tree a -> [a]
treeToList (Leaf value) = [value]
treeToList (Branch a lTree rTree) = a : treeToList lTree ++ treeToList rTree 

maxTree :: Ord a => Tree a -> a
maxTree tree = maximum (treeToList tree)

depthTree :: Tree a -> Int
depthTree (Branch a lTree rTree) = temp 0 (Branch a lTree rTree)
    where
        temp i (Leaf _) = i + 1
        temp i (Branch _ lTree rTree) = max (temp (i+1) lTree) (temp (i+1) rTree)

getGreaterElements :: Ord a => Tree a -> a -> [a]
getGreaterElements a b = filter(>b) (treeToList a)

treeToString :: Show a => Tree a -> String
treeToString (Leaf a) = show a
treeToString (Branch a lTree rTree) = show a ++ "(" ++ treeToString lTree ++ "," ++ treeToString rTree ++ ")"
