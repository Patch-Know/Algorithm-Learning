/*实现二叉树类并进行测试,二叉树的结点由单个字符组成。二叉树的操作包括:
(1)构造空二叉树
(2)根据先序遍历序列建立二叉树,使用#表示空结点
(3)判别二叉树是否为空
(4)先序遍历、中序遍历、后序遍历递归实现
(5)对二叉树进行层次遍历
(6)先序遍历、中序遍历非递归实现
(7)求二叉树的结点数、叶子结点数、度为1和度为2的结点数
(8)计算二叉树的高度和宽度
(9)查找指定元素的父结点
(10)清空已有二叉树
(11)按层次顺序插入一个新结点
(12)拷贝构造函数、赋值重载运算、析构函数
(13)判断两棵二叉树是否互为镜像
(14)输出从根结点到指定成员的路径
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory>
#include<queue>
#include<stack>
#include<functional>
#include<utility> //std::move

class my_tree
{
public:
    using value_type = char;
private:
    struct node{
        value_type val;
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;

        explicit node(value_type v):val(v){}
    };
    
    std::unique_ptr<node> root;
    
    void CT_PreOrder_recursion(const std::string &s,int &i, std::unique_ptr<node> &r);
    void PreOrder_recursion(const node *)const; 
    void InOrder_recursion(const node *)const;
    void PostOrder_recursion(const node *)const;
    struct cnt_node{
        int d0,d1,d2;
        cnt_node operator+(const cnt_node &o) const {
            return {d0+o.d0,d1+o.d1,d2+o.d2};
        }
        cnt_node& operator+=(const cnt_node &o){
            d0+=o.d0;
            d1+=o.d1;
            d2+=o.d2;
            return *this;
        }
    };
    cnt_node cnt_recursion(const node *r)const;
    
    // 内部：返回目标结点的父结点裸指针，找不到返回 nullptr
    const node* findParent_rec(const node* r, value_type target) const;
    bool PrintPath_rec(const node* r,value_type target,std::stack<value_type> &st) const;

    // 递归深拷贝一棵子树，返回新的 unique_ptr 链
    static std::unique_ptr<node> clone(const node* r) {
        if (!r) return nullptr;
        auto p = std::make_unique<node>(r->val);
        p->left  = clone(r->left.get());
        p->right = clone(r->right.get());
        return p;
    }

    // 判断以 a、b 为根的两棵子树是否互为镜像
    static bool mirror(const node* a, const node* b) {
        if (!a && !b) return true;       // 都空 → 镜像
        if (!a || !b) return false;      // 一空一非空 → 不是
        if (a->val != b->val) return false;  // 值不同 → 不是
        return mirror(a->left.get(),  b->right.get())   // 交叉：左对右
            && mirror(a->right.get(), b->left.get());   // 交叉：右对左
    }

public:
    my_tree() = default;
    my_tree(const my_tree& o);                            // 拷贝构造
    my_tree& operator=(const my_tree& o);                 // 拷贝赋值
    my_tree(my_tree&& o) noexcept = default;              // 移动构造
    my_tree& operator=(my_tree&& o) noexcept = default;   // 移动赋值
    ~my_tree() = default;                                 // 析构

    void clear(){root.reset();} //等价于root = nullptr
    void CT_PreOrder(const std::string &s);
    bool empty() const{return root==nullptr;} //应标const,否则 const my_tree& 不能调 empty()
    void PreOrder_R()const;
    void InOrder_R()const;
    void PostOrder_R()const;
    void LevelOrder()const;
    void PreOrder_NR()const;
    void InOrder_NR()const;
    void cnt_R()const;
    int width() const;
    int height() const;
    bool findParent(value_type target) const;
    void PrintPath(value_type target) const;
    void LevelInsert(value_type target);
    bool isMirrorOf(const my_tree& other) const; 
    bool isSymmetric() const;
};

my_tree::my_tree(const my_tree& o)
    : root(clone(o.root.get())) {}

my_tree& my_tree::operator=(const my_tree& o) {
    if (this != &o) {          // 自我赋值保护
        my_tree tmp(o);        // 先深拷贝到临时对象（异常安全）
        std::swap(root, tmp.root);  // 交换：this 拿到新树，tmp 持有旧树
    }                          // tmp 离开作用域，旧树被自动释放
    return *this;
}

void my_tree::CT_PreOrder_recursion(const std::string &s,int &i,std::unique_ptr<node> &r)
{
    if(i>=static_cast<int>(s.size()) ) return;
    if(s[i]=='#'){ ++i; return;}
    r=std::make_unique<node>(s[i++]);
    CT_PreOrder_recursion(s,i,r->left);
    CT_PreOrder_recursion(s,i,r->right);

}
void my_tree::CT_PreOrder(const std::string &s)
{
    int i=0;
    root.reset();
    CT_PreOrder_recursion(s,i,root);
}

void my_tree::PreOrder_recursion(const node* r)const{
    if (!r) return;
    std::cout << r->val << ' ';
    PreOrder_recursion(r->left.get());
    PreOrder_recursion(r->right.get());
}

void my_tree::InOrder_recursion(const node* r)const{
    if (!r) return;
    InOrder_recursion(r->left.get());
    std::cout << r->val << ' ';
    InOrder_recursion(r->right.get());
}

void my_tree::PostOrder_recursion(const node* r)const {
    if (!r) return;
    PostOrder_recursion(r->left.get());
    PostOrder_recursion(r->right.get());
    std::cout << r->val << ' ';
}


void my_tree::PreOrder_R() const
{
    PreOrder_recursion(root.get());
}

void my_tree::InOrder_R() const
{
    InOrder_recursion(root.get());    
}

void my_tree::PostOrder_R() const
{
    PostOrder_recursion(root.get());    
}

void my_tree::LevelOrder() const 
{
    if(!root) return;
    std::queue<const node*> curLevel;
    curLevel.push(root.get());
    while(!curLevel.empty()){
        int n=static_cast<int>(curLevel.size()); //只存本层节点数即可
        while(n--){
            const node *pn=curLevel.front();
            std::cout << pn->val << ' ';
            curLevel.pop();
            if(pn->left) curLevel.push(pn->left.get());
            if(pn->right) curLevel.push(pn->right.get());
        }
        std::cout << '\n'; //(可选)每层一行
    }
}

void my_tree::LevelInsert(value_type target)
{
    if(!root){
        root=std::make_unique<node>(target);
        return;
    }
    std::queue<node*> curLevel;
    curLevel.push(root.get());
    while(!curLevel.empty()){
        int n=static_cast<int>(curLevel.size()); //只存本层节点数即可
        while(n--){
            node *pn=curLevel.front();
            curLevel.pop();
            if(pn->left) curLevel.push(pn->left.get());
            else{
                pn->left=std::make_unique<node>(target);
                return;
            }
            if(pn->right) curLevel.push(pn->right.get());
            else{
                pn->right=std::make_unique<node>(target);
                return;
            }
        }
    }

}

void my_tree::PreOrder_NR() const
{
    if(!root) return;
    std::stack<const node*> st;
    st.push(root.get());
    while(!st.empty()){
        const node *pn=st.top();
        st.pop();
        if(!pn) continue;
        std::cout << pn->val << ' ';
        st.push(pn->right.get());
        st.push(pn->left.get());
    }
}

void my_tree::InOrder_NR() const
{
    if(!root) return;
    std::stack<const node*> st;
    const node *pn=root.get();
    while(pn || !st.empty()){
        while(pn){
            st.push(pn);
            pn=pn->left.get();
        }
        pn=st.top();
        st.pop();
        std::cout << pn->val << ' ';
        pn=pn->right.get(); //关键,是指向右孩子走流程,不是push
    }
}

my_tree::cnt_node my_tree::cnt_recursion(const node *r) const
{
    if(!r) return {0,0,0};
    if(r->left==nullptr && r->right==nullptr) return {1,0,0};
    if(r->left && r->right){
        return cnt_node{0,0,1}+cnt_recursion(r->left.get())+cnt_recursion(r->right.get());
    }
    return cnt_node{0,1,0}+cnt_recursion(r->left.get())+cnt_recursion(r->right.get());
}

void my_tree::cnt_R() const
{
    auto res=cnt_recursion(root.get());
    std::cout << "number of nodes: " << res.d0+res.d1+res.d2 << '\n';
    std::cout << "number of leaf-nodes: " << res.d0 << '\n';
    std::cout << "number of du1-nodes: " << res.d1 << '\n';
    std::cout << "number of du2-nodes: " << res.d2 << '\n';
}

int my_tree::width() const
{
    if (!root) return 0;
    int maxW = 0;
    std::queue<const node*> q;
    q.push(root.get());
    while (!q.empty()) {
        int n = static_cast<int>(q.size());   // 本层结点数
        maxW = std::max(maxW, n);
        while (n--) {
            const node* p = q.front(); q.pop();
            if (p->left)  q.push(p->left.get());
            if (p->right) q.push(p->right.get());
        }
    }
    return maxW;
}

int my_tree::height() const {
    std::function<int(const node*)> h = [&](const node* r) -> int {
        return r ? 1 + std::max(h(r->left.get()), h(r->right.get())) : 0;
    };
    return h(root.get());
}

// 内部：返回目标结点的父结点裸指针，找不到返回 nullptr
const my_tree::node* my_tree::findParent_rec(const node* r, value_type target) const {
    if (!r) return nullptr;
    // 先看孩子是不是目标：是就直接返回当前结点 r
    if ((r->left  && r->left->val  == target) ||
        (r->right && r->right->val == target))
        return r;
    // 否则往下找
    if (const node* p = findParent_rec(r->left.get(),  target)) return p;
    return findParent_rec(r->right.get(), target);
}

bool my_tree::findParent(value_type target) const
{
    const node *p=findParent_rec(root.get(),target);
    if(!p) return false;
    std::cout << p->val << '\n';
    return true;
}

bool my_tree::PrintPath_rec(const node* r,value_type target,std::stack<value_type> &st)const
{
    if(!r) return false;
    if(r->val==target){
        st.push(r->val);
        return true;
    }
    if(PrintPath_rec(r->left.get(),target,st)){
        st.push(r->val);
        return true;
    }
    if(PrintPath_rec(r->right.get(),target,st)){
        st.push(r->val);
        return true;
    }
    return false;
}

void my_tree::PrintPath(value_type target) const
{
    std::stack<value_type> st;
    if(PrintPath_rec(root.get(),target,st)){
        while(!st.empty()){
            std::cout << st.top() << ' ';
            st.pop();
        }
    }else{
        std::cout << "Can't find " << target << '\n';
    }
}

bool my_tree::isMirrorOf(const my_tree& other) const{
    return mirror(root.get(), other.root.get());
}

bool my_tree::isSymmetric() const {
    return mirror(root ? root->left.get()  : nullptr,
                  root ? root->right.get() : nullptr);
}


int main()
{
    std::cout << std::boolalpha;

    // ================= (1) Construct empty tree / (3) Empty check =================
    std::cout << "========== (1)(3) Empty tree / empty() ==========\n";
    my_tree t;
    std::cout << "New empty tree, empty() = " << t.empty() << '\n';

    // ================= (2) Build tree from preorder sequence =================
    // Preorder: A B D # # E # # C F # # G # #
    std::cout << "\n========== (2) Build from preorder ==========\n";
    t.CT_PreOrder("ABD##E##CF##G##");
    std::cout << "After build, empty() = " << t.empty() << '\n';

    // ================= (4) Recursive traversals =================
    std::cout << "\n========== (4) Recursive traversals ==========\n";
    std::cout << "Preorder : "; t.PreOrder_R();  std::cout << '\n';
    std::cout << "Inorder  : "; t.InOrder_R();   std::cout << '\n';
    std::cout << "Postorder: "; t.PostOrder_R(); std::cout << '\n';

    // ================= (5) Level-order traversal =================
    std::cout << "\n========== (5) Level-order traversal ==========\n";
    t.LevelOrder();

    // ================= (6) Non-recursive traversals =================
    std::cout << "\n========== (6) Non-recursive traversals ==========\n";
    std::cout << "Preorder: "; t.PreOrder_NR(); std::cout << '\n';
    std::cout << "Inorder : "; t.InOrder_NR();  std::cout << '\n';

    // ================= (7) Node counts: total / leaf / degree1 / degree2 =================
    std::cout << "\n========== (7) Node statistics ==========\n";
    t.cnt_R();

    // ================= (8) Height / width =================
    std::cout << "\n========== (8) Height / width ==========\n";
    std::cout << "Height = " << t.height() << '\n';   // expect 3
    std::cout << "Width  = " << t.width()  << '\n';   // expect 4

    // ================= (9) Find parent of a node =================
    std::cout << "\n========== (9) Find parent ==========\n";
    for (char c : {'A','B','C','D','E','F','G','X'}) {
        std::cout << "Parent of '" << c << "': ";
        if (!t.findParent(c))
            std::cout << "none (root or not found)";
    }

    // ================= (10) Clear =================
    std::cout << "\n========== (10) Clear ==========\n";
    my_tree tClear = t;             // copy first, keep t intact for later tests
    tClear.clear();
    std::cout << "After clear(), empty() = " << tClear.empty() << '\n';

    // ================= (11) Level-order insertion =================
    std::cout << "\n========== (11) Level-order insertion ==========\n";
    my_tree tIns;
    for (char c : {'A','B','C','D','E','F','G'})
        tIns.LevelInsert(c);
    std::cout << "After LevelInsert A~G, level order:\n";
    tIns.LevelOrder();              // expect A / B C / D E F G
    std::cout << "Node stats: "; tIns.cnt_R();

    // ================= (12) Copy ctor / assignment / move =================
    std::cout << "\n========== (12) Copy / assignment / move ==========\n";
    my_tree orig;
    orig.CT_PreOrder("ABD##E##CF##G##");

    my_tree copyCtor(orig);             // copy constructor
    my_tree copyAssign;
    copyAssign = orig;                  // copy assignment
    my_tree moveCtor(std::move(orig));  // move constructor

    my_tree src;  src.CT_PreOrder("XY##Z##");
    my_tree moveAssign;
    moveAssign = std::move(src);        // move assignment

    std::cout << "moveCtor preorder  : "; moveCtor.PreOrder_R(); std::cout << '\n';
    std::cout << "moveAssign preorder: "; moveAssign.PreOrder_R(); std::cout << '\n';
    std::cout << "Moved-from orig empty() = " << orig.empty() << '\n';
    std::cout << "Moved-from src  empty() = " << src.empty()  << '\n';

    // Verify deep copy: modifying copyCtor must not affect copyAssign
    copyCtor.LevelInsert('Z');
    std::cout << "copyCtor after insert Z, stats:\n"; copyCtor.cnt_R();
    std::cout << "copyAssign stats (should still be 7):\n"; copyAssign.cnt_R();

    // ================= (13) Mirror / symmetric =================
    std::cout << "\n========== (13) Mirror / symmetric ==========\n";
    my_tree a, m, a2, sym;
    a .CT_PreOrder("AB##C##");   // A(B, C)
    m .CT_PreOrder("AC##B##");   // A(C, B) -- mirror of a
    a2.CT_PreOrder("AB##C##");   // identical to a
    sym.CT_PreOrder("AB##B##");  // A(B, B) -- self-symmetric

    std::cout << "a and m   are mirrors   : " << a.isMirrorOf(m)  << '\n';  // true
    std::cout << "a and a2  are mirrors   : " << a.isMirrorOf(a2) << '\n';  // false
    std::cout << "sym is symmetric        : " << sym.isSymmetric() << '\n';  // true
    std::cout << "a   is symmetric        : " << a.isSymmetric()   << '\n';  // false

    // ================= (14) Path from root to target =================
    std::cout << "\n========== (14) Path root -> target ==========\n";
    for (char c : {'G','D','A','X'}) {
        std::cout << "To '" << c << "': ";
        t.PrintPath(c);
    }

    std::cout << "\n========== All tests finished ==========\n";
    return 0;
}