1) GCD (greatest common divisor)

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

//maths behind it

x|a (x divide a) -> a%x=0
x|b (x divide b) -> b%x=0
then x|(a-b) -> (a-b)%x=0

gcd(a,b) -> gcd(a-b,b) -> gcd(a-xb,b) -> gcd(a%b,b) (I'm left with reminder) -> gcd(b,a%b)

gcd(a,b) , a<b  => gcd(b, a%b) => gcd(b,a) , here b>a

// time complexity

in one step -> swapped if a<b
in second step -> reduced to x/2 , gcd(x,y) where x>y

gcd(x%y,y) -> < x/2   , where x>y

how?

case1 - if y<=x/2 then result gcd(x%y,y) will be surely <= x/2    (a%b result lies in [0..b-1])
case2 - if y>x/2, then x%y < x/2, visualize on number line

time complexity -> o(log(min(a,b)))

2) LCM (least common multiple)

gcd(a,b) x lcm(a,b) = a x b

3) Prime factorization | divisor

int prime

