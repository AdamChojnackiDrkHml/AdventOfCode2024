module Main where
import Data.List

main :: IO ()
main = do
    content <- readFile "data/data.txt"
    let
        lists = unzip . readStringLines . lines $ content
    print . trick $ lists


parseLine :: [String] -> (Int, Int)
parseLine [x, y] = (read x, read y)
parseLine _ = (0, 0)

readStringLines :: [String] -> [(Int, Int)]
readStringLines = map (parseLine . words)

calcDistance :: Num a => [(a, a)] -> a
calcDistance [] = 0
calcDistance ((x, y):xys) = abs (y - x) + calcDistance xys

pairUp :: (Ord a) => [a] -> [a] -> [(a, a)]
pairUp x y = zip (sort x) (sort y)

trick :: (Ord a, Num a) => ([a], [a]) -> a
trick (x, y) = calcDistance (pairUp x y)

