#include <bits/stdc++.h>
#define int long long
#define task "Divisions_Miller_Rabin."

using namespace std;
// Phép nhân Ấn Độ (a * b) % mod. Sử dụng để tránh tràn số khi thực hiện phép nhân.
int indian_multiplication(int a, int b, int mod)
{
    if (b == 0)
        return 0;

    int half = indian_multiplication(a, b / 2LL, mod) % mod;

    if (b & 1)
        return (half + half + a) % mod;
    else
        return (half + half) % mod;
}

// Tính (a^b) % mod. Sử dụng kết hợp với phép nhân Ấn Độ để tránh tràn số khi thực hiện phép nhân.
int modular_exponentiation(int a, int b, int mod)
{
    if (b == 0)
        return 1LL;

    int half = modular_exponentiation(a, b / 2LL, mod) % mod;
    int product = indian_multiplication(half, half, mod);

    if (b & 1)
        return indian_multiplication(product, a, mod);
    else
        return product;
}

vector < int > eratosthenes_sieve(int max_value)
{
    vector < bool > is_prime(max_value + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= max_value; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= max_value; j += i)
                is_prime[j] = false;

    vector < int > primes;
    for (int i = 2; i <= max_value; ++i)
        if (is_prime[i])
            primes.push_back(i);

    return primes;
}

// Kiểm tra nguyên tố Miller - Rabin k lần.
bool check_prime_by_miller_rabin(int n, int k)
{
    // Xử lý trước các trường hợp đặc biệt.
    if (n < 2)
        return false;

    if (n != 2 && n % 2 == 0)
        return false;

    // Tìm d là số lẻ sao cho n - 1 = 2^r * d và r != 0.
    // Sau khi tìm ra d, r sẽ bằng số lần nhân 2 vào d để tiến tới n - 1.
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Bắt đầu kiểm tra .
    for (int i = 1; i <= k; ++i)
    {
        // Chọn a là một số ngẫu nhiên trong đoạn [2, n - 1].
        int a = rand() % (n - 1) + 1;
        int temp = d;

        // Tính a^d % n.
        int mod_val = modular_exponentiation(a, temp, n);

        // Trong khi d != n và a^(2^k * d) % n != 1 và a^(2^k * d) % n != (n - 1).
        // Bước này bản chất là thử kiểm tra mọi x(k) % n với k = 0...r.
        while (temp != n - 1 && mod_val != 1 && mod_val != n - 1)
        {
            mod_val = indian_multiplication(mod_val, mod_val, n);
            temp *= 2;
        }

        // Nếu không thể chạm được tới x(r) thì nghĩa là đã tồn tại giá trị k khiến cho
        // a^(2^k * d) % n != 1 hoặc a^(2^k * d) % n != -1
        if (mod_val != n - 1 && temp % 2 == 0)
            return false;
    }

    return true;
}
bool sqrt_is_integer(int n)
{
    int squaroot = sqrt(n);

    return (squaroot * squaroot == n);
}

void solution(int n, int k)
{
    // Sàng lọc các số nguyên tố từ 1 tới 10^6
    // (bằng với n^(1/3) trong trường hợp lớn nhất).
    vector < int > primes = eratosthenes_sieve(1000000);

    // Tính F(x) với x bao gồm tất cả các thừa số nguyên tố nhỏ hơn hoặc bằng n^(1/3).
    // Lưu luôn F(x) vào res.
    long long res = 1;
    for (int p: primes)
    {
        if (p * p * p > n)
            break;

        int cnt = 0;
        while (n % p == 0)
        {
            n /= p;
            ++cnt;
        }

        res *= (cnt + 1);
    }

    // Tính F(y) với y bao gồm tất cả các thừa số nguyên tố lớn hơn n^(1/3).
    // Chắc chắn y chỉ có thể ở một trong ba trường hợp: là số nguyên tố, là bình phương
    // của một số nguyên tố hoặc là tích của hai số nguyên tố phân biệt.
    if (check_prime_by_miller_rabin(n, k))
        res *= 2LL;
    else if (sqrt_is_integer(n) && check_prime_by_miller_rabin((int)sqrt(n), k))
        res *= 3LL;
    else if (n != 1)
        res *= 4LL;

    cout << res;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    solution(n, 10);

    return 0;
}
