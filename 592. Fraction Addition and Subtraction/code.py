from math import gcd

def fraction_addition(expression: str) -> str:
    numerator, denominator = 0, 1
    i = 0
    while i < len(expression):
        # Read the sign
        sign = 1
        if expression[i] in '-+':
            sign = -1 if expression[i] == '-' else 1
            i += 1
            
        # Read the numerator
        num = 0
        while i < len(expression) and expression[i].isdigit():
            num = num * 10 + int(expression[i])
            i += 1
            
        # Skip the '/'
        i += 1
        
        # Read the denominator
        denom = 0
        while i < len(expression) and expression[i].isdigit():
            denom = denom * 10 + int(expression[i])
            i += 1
            
        # Calculate the result
        numerator = numerator * denom + sign * num * denominator
        denominator *= denom
        g = gcd(abs(numerator), denominator)
        numerator //= g
        denominator //= g
    
    return f"{numerator}/{denominator}"

# Test cases
expression1 = "-1/2+1/2"
expression2 = "-1/2+1/2+1/3"
expression3 = "1/3-1/2"

print(fraction_addition(expression1))  # Output: "0/1"
print(fraction_addition(expression2))  # Output: "1/3"
print(fraction_addition(expression3))  # Output: "-1/6"
