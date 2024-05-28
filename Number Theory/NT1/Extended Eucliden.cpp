//GCD(a , b) = ax + by
//to find x , y
ll extended_euclid(ll a, ll b , ll& x , ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    //when reach base case ,,, calc x = prev_y , y = prev_x - q*x
    ll g = extended_euclid(b, a % b, y, x);
    y -= (a / b) * x;

    return g;
}
//Observation of Equation : https://www.youtube.com/live/2k0TPnZyobY?si=HMCSfEZTBycaRHst
