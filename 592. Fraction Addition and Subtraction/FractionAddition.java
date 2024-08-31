import java.util.*;

public class FractionAddition {
    // Function to find the greatest common divisor (GCD)
    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static String fractionAddition(String expression) {
        int numerator = 0, denominator = 1;
        int i = 0;
        while (i < expression.length()) {
            // Read the sign
            int sign = 1;
            if (expression.charAt(i) == '-' || expression.charAt(i) == '+') {
                sign = expression.charAt(i++) == '-' ? -1 : 1;
            }
            
            // Read the numerator
            int num = 0;
            while (i < expression.length() && Character.isDigit(expression.charAt(i))) {
                num = num * 10 + expression.charAt(i++) - '0';
            }
            
            // Skip the '/'
            i++;
            
            // Read the denominator
            int denom = 0;
            while (i < expression.length() && Character.isDigit(expression.charAt(i))) {
                denom = denom * 10 + expression.charAt(i++) - '0';
            }
            
            // Calculate the result
            numerator = numerator * denom + sign * num * denominator;
            denominator *= denom;
            int g = gcd(Math.abs(numerator), denominator);
            numerator /= g;
            denominator /= g;
        }
        
        return numerator + "/" + denominator;
    }

    public static void main(String[] args) {
        // Test cases
        String expression1 = "-1/2+1/2";
        String expression2 = "-1/2+1/2+1/3";
        String expression3 = "1/3-1/2";
        
        System.out.println(fractionAddition(expression1)); // Output: "0/1"
        System.out.println(fractionAddition(expression2)); // Output: "1/3"
        System.out.println(fractionAddition(expression3)); // Output: "-1/6"
    }
}
