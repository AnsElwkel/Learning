//Observation of Equation : https://www.youtube.com/live/2k0TPnZyobY?si=HMCSfEZTBycaRHst

//GCD(a , b) = ax + by
//to find x , y
ll extended_euclid(ll a, ll b , ll& x , ll& y) { // Recursive
    if(a < 0){
        ll tmp = extended_euclid(-a , b , x , y);
        x *= -1;
        return tmp;
    }

    if(b < 0){
        ll tmp = extended_euclid(a , -b , x , y);
        y *= -1;
        return tmp;
    }

    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    //when reach base case ,,, calc x = prev_y , y = prev_x - q*x
    ll g = extended_euclid(b, a % b, y, x);
    y -= (a / b) * x;

    return g;
}

ll extended_euclid(ll a,ll b,ll &x,ll &y)
{//Iterative
    ll nx,ny,q,temp;
    x=ny=1;
    y=nx=0;
    while(b)
    {
        q=a/b;
        temp=a; a=b; b=temp%b;
        temp=nx; nx=x-q*nx; x=temp;
        temp=ny; ny=y-q*ny; y=temp;
    }
    return a;
}

// Observation ->  https://www.youtube.com/live/6_Hjovg4930?si=ZVGbVNCfMMIMcJ2B

ll linearDiophantine(ll a, ll b, ll c, ll& x , ll& y){
    ll g = extended_euclid(a , b , x , y);

    if(c % g == 0) x *= c / g , y *= c / g;

    return g;
}

/*
 ax = b (mod n) -> Given  a , b , n -> find x
 -> ax = b + qn
 -> ax + (-q)n = b    y = -q
 -> ax + ny = b       similar to (ax + by = c)
 -> solve by LDE -> Ex_Eculidean
 -> because we play in mod space n -> n solutions max to Equation
 -> gcd(a , n) unique solution
  */

vector<ll> modularEquation(ll a , ll b , ll n){
    vector<ll> sols;
    ll x , y , g;
    g = extended_euclid(a, n , x , y);

    if(b % g) return sols; //No solutions

    x = ((b * x / g)%n + n) % n;

    for (int i = 0; i < g; ++i) //Generate Solutions (Bezout Identity)
        sols.push_back( (x + i * n / g) % n);

    sort(all(sols));
    return sols;
}