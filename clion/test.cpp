/*                     _ooOoo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                       O\ = /O
                   ____/`---'\____
                 .   ' \\| |// `.
                  / \\||| : |||// \
                / _||||| -:- |||||- \
                  | | \\\ - /// | |
                | \_| ''\---/'' | |
                 \ .-\__ `-` ___/-. /
              ___`. .' /--.--\ `. . __
           ."" '< `.___\_<|>_/___.' >'"".
          | | : `- \`.;`\ _ /`;.`/ - ` : | |
            \ \ `-. \_ __\ /__ _/ .-` / /
    ======`-.____`-.___\_____/___.-`____.-'======
                       `=---='                      */
#include <bits/stdc++.h>
#include <functional>
#include <string_view>

using i128 [[maybe_unused]] = __int128;
const i128 &INT128_MAX = (i128(INT64_MAX) << 64) | UINT64_MAX;
const i128 &INT128_MIN [[maybe_unused]] = ~INT128_MAX;

i128 operator""_i(const unsigned long long value) {
    return i128(value);
}

i128 operator""_i(const char *str, std::size_t len) {
    bool f = str[0] == '-';
    if (not std::all_of(str + f, str + len, isdigit))
        throw std::invalid_argument("无法转换为整数");
    i128 value = 0;
    for (size_t i = 0 + f; i < len; ++i)
        value = (value << 3) + (value << 1) + (str[i] ^ '0');
    return f ? -value : value;
}

std::istream &operator>>(std::istream &is, i128 &value) {
    value = 0;
    bool isNegative = false;
    int c = is.get();
    while (not isdigit(c)) {
        if (c == '-')
            isNegative = true;
        c = is.get();
    }
    while (isdigit(c)) {
        value = (value << 3) + (value << 1) + (c ^ '0');
        c = is.get();
    }
    if (isNegative)
        value = -value;
    return is;
}

std::ostream &operator<<(std::ostream &os, i128 value) {
    if (value == 0) {
        os.put('0');
        return os;
    }
    static char sta[40];
    unsigned char top = 0;
    if (value < 0) {
        sta[top++] = static_cast<char>(-(value % 10));
        value /= 10;
        value = ~value + 1;
        os.put('-');
    }
    for (; value; value /= 10)
        sta[top++] = static_cast<char>(value % 10);
    for (; top--;)
        os.put(static_cast<char>(sta[top] ^ '0'));
    return os;
}

i128 abs [[maybe_unused]] (const i128 &v) {
    return v > 0 ? v : -v;
}

using namespace std;
using i64 [[maybe_unused]] = long long;
using u64 [[maybe_unused]] = unsigned long long;
#ifdef _STD
template <typename Key, typename Value>
using hash_map [[maybe_unused]] = unordered_map<Key, Value>;
template <typename T> using hash_set [[maybe_unused]] = unordered_set<T>;
template <typename Key, typename Value>
using rb_tree_map [[maybe_unused]] = map<Key, Value>;
template <typename T> using rb_tree_set [[maybe_unused]] = set<T>;
template <typename T, typename Comparer = greater<T>>
using heap [[maybe_unused]] = priority_queue<T, vector<T>, Comparer>;
#else
#include <ext/pb_ds/assoc_container.hpp>
template <typename Key, typename Value>
using hash_map [[maybe_unused]] = __gnu_pbds::gp_hash_table<Key, Value>;
template <typename T>
using hash_set [[maybe_unused]] =
    __gnu_pbds::gp_hash_table<T, __gnu_pbds::null_type>;
template <typename Key, typename Value>
using rb_tree_map [[maybe_unused]] =
    __gnu_pbds::tree<Key, Value, less<Key>, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
template <typename T>
using rb_tree_set [[maybe_unused]] =
    __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
using trie [[maybe_unused]] = __gnu_pbds::trie<
    string, __gnu_pbds::null_type, __gnu_pbds::trie_string_access_traits<>,
    __gnu_pbds::pat_trie_tag, __gnu_pbds::trie_prefix_search_node_update>;
    #include <ext/pb_ds/priority_queue.hpp>
template <typename T, typename Comparer = greater<T>>
using heap [[maybe_unused]] =
    __gnu_pbds::priority_queue<T, greater<T>, __gnu_pbds::rc_binomial_heap_tag>;
    #include <ext/rope>
using namespace __gnu_cxx;
#endif
const char &ln = '\n';

template <typename T, typename V> T as [[maybe_unused]] (const V &val) {
    return static_cast<T>(val);
}

template <typename T, class Begin, class End>
void println [[maybe_unused]] (Begin begin, End end, const char *c = " ") {
    copy(begin, end, ostream_iterator<T>(cout, c));
    cout.put('\n');
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<set<i64>> graph(n + 1);
    for (i64 i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v;
        graph[u].emplace(v);
        graph[v].emplace(u);
    }
    graph[1].emplace(n + 1);
    i64 nxt = 2;
    i64 ans = 0;
    function<void(const i64 &u)> dfs = [&](const i64 &u) {
        if (u == n + 1)
            return;
        for (auto &&v : graph[u]) {
            if (v < nxt)
                continue;
            while (v >= nxt) {
                ans += v > nxt;
                dfs(nxt++);
            }
        }
    };

    dfs(1);
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}
