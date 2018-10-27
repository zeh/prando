main :: IO ()
main = do
    putStrLn "Enter N: "
    number <- getLine
    let n = read number - 1 :: Integer
    putStrLn (show ((sum [3,6..n]) + (sum [5,10..n]) - sum [15,30..n]))
