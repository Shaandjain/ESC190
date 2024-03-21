import numpy as np

def make_change(coins, amount):
    OPT = [np.inf] * (amount + 1)  # Initialize OPT array with infinity
    OPT[0] = 0  # Base case: 0 coins needed to make 0c
    
    for i in range(1, amount + 1):
        for c in coins:
            if i - c >= 0:
                OPT[i] = min(OPT[i], OPT[i - c] + 1)
                
    return OPT

print(make_change([1,5,10], 8))




def find_coins(coins, amount):
    OPT = make_change(coins, amount)
    result = []
    while amount > 0:
        for c in coins:
            if amount - c >= 0 and OPT[amount] == OPT[amount - c] + 1:
                result.append(c)
                #remove the coin from the total
                amount -= c
                break  # found the optimal next step, move on to next
    return result

print(find_coins([1,4,5], 8)) # [4, 4]


