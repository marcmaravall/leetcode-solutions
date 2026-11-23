class ProductOfNumbers {
private:
    std::vector<int> m_products = {1};

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num != 0) {
            m_products.push_back(num*m_products.back());
        } else {
            m_products = {1};
        }
    }
    
    int getProduct(int k) {
        const int n = m_products.size();
        if (k >= n) {
            return 0;
        }
        return m_products[n-1]/m_products[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */