#include"utility.h"
#include"life.h"

void instructions()
{
//     cout <<"生命游戏在一个无边界的矩形网格上进行，这个矩形网格中的每个单元可被占据，也可不被占据.\n"
//     "被占据的单元称为活的，而不被占据的单元称为死的。\n"
//     "一个单元是活的还是死的是根据其周围活的邻居单元的数目而一代一代地发生变化的。一代一代变化的具体规则如下：\n"
// "给定单元的邻居单元指的是与它在垂直、水平或对角方向上相接的8个单元。\n"
// "如果一个单元是活的,则如果它具有2个或3个活的邻居单元,则该单元在下一代还是活的。\n"
// "如果一个单元是活的,则如果它具有0个或1个、4个或4个以上活的邻居单元,则该单元在下一代会因为孤独或拥塞而死亡。\n"
// "如果一个单元是死的,则如果它恰好具有3个活的邻居单元,则该单元在下一代会复活,否则该单元在下一代仍然是死的。\n";
    cout << "生命游戏操作说明:\n";
    cout << "先根据提示进行初始化配置\n"
    "再重复选择是否要查看下一轮的状态\n"
    "直到输入n退出\n";
}

bool user_says_yes()
{
    std::cout << "input y/n to continue:\n";

    char ch;
    if (!(std::cin >> ch)) {
        return false; // EOF 或输入错误
    }

    // 清掉这一行剩余字符，包括换行
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return ch == 'y' || ch == 'Y';
}

int Life::neighbour_count(int row,int col)
{
    int count=0;
    for(int i=row-1;i<=row+1;i++){
        for(int j=col-1;j<=col+1;j++){
            count+=grid[i][j];
        }
    }
    count-=grid[row][col];
    return count;
}

void Life::update()
{
    int row,col;
    int new_grid[MaxRow+2][MaxCol+2];

    for(row=1;row<=MaxRow;row++){
        for(col=1;col<=MaxCol;col++){
            switch(neighbour_count(row,col)){
                case 2:new_grid[row][col]=grid[row][col];break;
                case 3:new_grid[row][col]=1;break;
                default: new_grid[row][col]=0;
            }
        }
    }

    for(row=1;row<=MaxRow;row++){
        for(col=1;col<=MaxCol;col++){
            grid[row][col]=new_grid[row][col];
        }
    }
}

void Life::keyboard_init()
{
    cout << "List the coordinates for living cells.\n";
    cout << "Terminate the list with the special pait (-1,-1)\n";
    int row,col;
    cin >> row >> col;
    while(row !=-1 || col!=-1){
        if(row>=1 && row<=MaxRow){
            if(col>=1 && col<=MaxCol){
                grid[row][col]=1;
            }else{
                cout << "Col " << col << " is out of range.\n";
            }
        }else{
            cout << "Row " << row << " is out of range.\n";
        }
        cin >> row >> col;
    }
}

void Life::txtfile_init()
{
    string filename;
    cout << "Please input filename: ";
    getline(cin,filename);
    ifstream infile(filename.c_str());
    if(!infile.is_open()){
        cout << "Can't open " << filename << endl;
        exit(EXIT_FAILURE);
    }
    int row,col;
    while(infile >> row >> col && (row !=-1 || col!=-1)){
        if(row>=1 && row<=MaxRow){
            if(col>=1 && col<=MaxCol){
                grid[row][col]=1;
            }else{
                cout << "Col " << col << " is out of range.\n";
            }
        }else{
            cout << "Row " << row << " is out of range.\n";
        }
    }
}

void Life::init()
{
    memset(grid,0,sizeof(grid));
    cout << "Choose keyboard or txtfile (k/t) to input: " << endl;
    char ch;
    cin >> ch;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(ch=='k' || ch=='K') keyboard_init();
    else txtfile_init();
}

void Life::print()
{
    int row,col;
    cout << "\nThe current Life configuration is:\n";
    for(row=1;row<=MaxRow;row++){
        for(col=1;col<=MaxCol;col++){
            cout << (grid[row][col]==1?" x ":"   ");
        }
        cout << endl;
    }
}