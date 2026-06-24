class Bank {
private:
    std::vector<long long> accounts {};
    int n = 0;

public:
    Bank(vector<long long>& balance) {
        accounts = std::move(balance);
        n = accounts.size();
    }
    
    #define CHECK(a) if ((a-1) >= n || (a-1) < 0) return false;

    bool transfer(int account1, int account2, long long money) {
        CHECK(account1);
        CHECK(account2);

        if (accounts[account1-1] < money) return false;
        accounts[account1-1] -= money;
        accounts[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        CHECK(account);
        accounts[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        CHECK(account);
        if (accounts[account-1] < money) return false;
        accounts[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */