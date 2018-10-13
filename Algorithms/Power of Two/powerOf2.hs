checkNum :: Integer -> Bool
checkNum 1 = True

checkNum x
  | x <= 0                 = False
  | (x `mod` 2) == 1       = False
  | (x `mod` 2) == 0       = checkNum (x `div` 2)
