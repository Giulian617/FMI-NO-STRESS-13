#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;

int main()
{
    int N;
    scanf("%d", &N);
    assert(1 <= N && N <= 100'000);

    auto ReadIp = [&]()
    {
        u32 a, b, c, d;
        scanf("%u.%u.%u.%u", &a, &b, &c, &d);
        assert(a <= 255);
        assert(b <= 255);
        assert(c <= 255);
        assert(d <= 255);
        return (a << 24) | (b << 16) | (c << 8) | d;
    };

    auto ReadIpRange = [&]() -> pair<int, int>
    {
        u32 ip = ReadIp();
        u32 mask;
        scanf("/%u", &mask);
        assert(mask <= 32);
        assert((ip & ((1 << (32 - mask)) - 1)) == 0);
        return {ip, mask};
    };

    // For a given range, which bases exist.
    vector<unordered_multiset<int>> ip_ranges(33);

    while (N--)
    {
        int type;
        scanf("%d", &type);
        assert(1 <= type && type <= 3);

        if (type <= 2)
        {
            auto [ip, mask] = ReadIpRange();
            if (type == 1)
            {
                // assert(!ip_ranges[mask].contains(ip));
                ip_ranges[mask].insert(ip);
            }
            else
            {
                assert(ip_ranges[mask].contains(ip));
                ip_ranges[mask].erase(ip_ranges[mask].find(ip));
            }
        }
        else
        {
            u32 ip = ReadIp();
            bool exists = 0;
            for (int mask = 0; mask <= 32; mask++)
            {
                // Remove the last mask bits.
                u32 base = ip & ((-1) << (32 - mask));
                exists |= ip_ranges[mask].contains(base);
            }

            printf("%s\n", exists ? "Da" : "Nu");
        }
    }
}
