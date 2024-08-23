#include <bits/stdc++.h> 
vector<long long int> addFraction(int a, int b, int c, int d)
{
	// Calculate the numerator and denominator
    long long int numerator = (long long int)a * d + (long long int)c * b;
    long long int denominator = (long long int)b * d;
    
    // Find the GCD of numerator and denominator
    long long int gcd = __gcd(numerator, denominator);
    
    // Simplify the fraction
    numerator /= gcd;
    denominator /= gcd;
    
    return {numerator, denominator};
}
