#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define int long long
// #define ll long long

class TrieNode {
public:
    TrieNode* children[2] = {nullptr, nullptr};
    ll isEnd = 0; // Indică dacă un subnet se termină aici

    ~TrieNode() {
        delete children[0];
        delete children[1];
    }
};

class BitwiseTrie {
private:
    TrieNode* root;

public:
    BitwiseTrie() {
        root = new TrieNode();
    }

    ~BitwiseTrie() {
        delete root;
    }

    void insert(ll ip, ll mask) {
        TrieNode* node = root;
        for (ll i = 31; i >= 32 - mask; --i) {
            ll bit = (ip >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
        node->isEnd++; // Setăm capătul subnet-ului
    }

    void remove(ll ip, ll mask) {
        auto node = root;
        for(ll i = 31; i >= 32 - mask; i--){
            node = node->children[(ip >> i) & 1];
            assert(node);
        }
        assert(node -> isEnd);
        node -> isEnd--;
    }

    bool query(ll ip) {
        auto node = root;
        for(ll i = 31; i >= 0; i--){
            node = node->children[(ip >> i) & 1];
            if(!node){
                return false;
            }
            if(node -> isEnd)
                return true;
        }
        return false;
    }
};

ll ipToUInt(const string& ip) {
    ll result = 0;
    ll shift = 24; // 8 biți pentru fiecare octet
    size_t start = 0, end;
    while ((end = ip.find('.', start)) != string::npos) {
        result |= (stoll(ip.substr(start, end - start)) << shift);
        start = end + 1;
        shift -= 8;
    }
    result |= (stoll(ip.substr(start))); // Adaugă ultimul octet
    // cerr << result << endl;
    // cerr <<bitset<32>(result) << endl;
    // cerr << (result >> 24) << "." << ((result >> 16) & 255) << "." << ((result >> 8) & 255) << "." << (result & 255) << endl; 
    return result;
}

int32_t main() {
    BitwiseTrie trie;

    ll Q;
    cin >> Q;

    for (ll i = 0; i < Q; ++i) {
        ll type;
        string subnet;
        cin >> type >> subnet;

        if (type == 1) {
            // Adăugăm subnet
            size_t pos = subnet.find('/');
            string ip = subnet.substr(0, pos);
            ll mask = stoll(subnet.substr(pos + 1));
            ll ipNum = ipToUInt(ip);
            trie.insert(ipNum, mask);
        } else if (type == 2) {
            // Ștergem subnet
            size_t pos = subnet.find('/');
            string ip = subnet.substr(0, pos);
            ll mask = stoll(subnet.substr(pos + 1));
            ll ipNum = ipToUInt(ip);
            trie.remove(ipNum, mask);
        } else if (type == 3) {
            // Interogăm IP
            ll ipNum = ipToUInt(subnet);
            cout << (trie.query(ipNum) ? "Da" : "Nu") << endl;
        }
    }

    return 0;
}
