const int MaxRow=20;
const int MaxCol=60;

class Life{
private:
    int grid[MaxRow+2][MaxCol+2];
    int neighbour_count(int row,int col);
    void keyboard_init();
    void txtfile_init();
public:
    void init();
    void print();
    void update();
};

void instructions();
bool user_says_yes();