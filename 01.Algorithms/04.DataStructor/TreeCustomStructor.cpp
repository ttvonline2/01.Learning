#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std; using namespace __gnu_pbds;

//**************************** CODING SPACE ****************************//
struct Rank {
    int elo;
    string username;
    int user_id;

    // So sánh theo Elo giảm dần, nếu Elo bằng thì so theo user_id
    bool operator<(const Rank& other) const {
        return tie(elo, user_id) > tie(other.elo, other.user_id);
    }
};

typedef tree<Rank, null_type, less<Rank>, rb_tree_tag, tree_order_statistics_node_update> RankTree;
int32_t main() {
    
   RankTree ranking;
    // Thêm người chơi
    ranking.insert({2400, "Alice", 1});
    ranking.insert({2200, "Bob", 2});
    ranking.insert({2300, "Charlie", 3});
    ranking.insert({2500, "David", 4});
    ranking.insert({2100, "Eve", 5});
     // 📌 Tìm người chơi rank thứ k (VD: k = 2, tính từ 0)
    int k = 2;
    auto it = ranking.find_by_order(k);
    if (it != ranking.end()) {
        cout << "Rank " << k + 1 << ": " << it->username << " (Elo: " << it->elo << ")\n";
    }

    // 📌 Tìm thứ hạng của người có Elo 2300
    Rank search_player = {2300, "", 0}; // ID không quan trọng khi tìm theo Elo
    int rank_position = ranking.order_of_key(search_player);
    cout << "Charlie đang đứng thứ: " << rank_position + 1 << endl;

    // 📌 Xóa người chơi Bob
    ranking.erase({2200, "Bob", 2});
    cout << "Bob đã bị xóa khỏi hệ thống.\n";
    return 0;
}