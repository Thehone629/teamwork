#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;
class Num2Uper
{
public:
    Num2Uper(const string& num)
    {

        this->setNum(num);
    }
    Num2Uper()
    {
        this->num_ = nullptr;
        this->word_ = nullptr;

    }
    const string& getWord() const
    {
        return word_;
    }
    void setWord(const string& word)
    {
        Num2Uper::word_ = word;
    }
    const string& getNum() const
    {
        return num_;
    }
    void setNum(const string& num)
    {
        Num2Uper::num_ = num;
    }
    virtual ~Num2Uper(){}
private:
    string word_;
    string num_;
    static string digits_[10];
    static  string unit_1[13];
    static  string unit_2[2];
public:

    void transform(){
        string part_int;
        string part_dec;
        int point_pos = int(this->getNum().find('.'));
        if (point_pos == -1) part_int = this->num_;
        else{
            part_int = num_.substr(0, point_pos);
            part_dec = num_.substr(point_pos + 1);
        }
        int part_int_size = part_int.size();
        bool zero_flag = true;
        bool prev_zero_flag = false;
        stack<string> result;
        for (int i = 0; i < part_int_size; ++i){
            int tmp = int(part_int[part_int_size - i - 1]) - 48;
            if (i % 4 == 0){
                if (tmp == 0){
                    if (!zero_flag && prev_zero_flag) result.push(digits_[0]);
                    result.push(unit_1[i]);
                    zero_flag = false;
                    prev_zero_flag = false;
                }
                else{
                    if (!zero_flag && prev_zero_flag)
                    {
                        result.push(digits_[0]);
                    }
                    result.push(unit_1[i]);
                    result.push(digits_[tmp]);

                    zero_flag = true;
                    prev_zero_flag = true;
                }

            }
            else{
                if (tmp == 0){
                    zero_flag = false;
                    continue;
                }
                else{
                    if (prev_zero_flag && !zero_flag)   result.push(digits_[0]);
                    result.push(unit_1[i]);
                    result.push(digits_[tmp]);
                    prev_zero_flag = true;
                    zero_flag = true;
                }
            }
        }
        string tmp;
        while (!result.empty()){
            tmp = result.top();
            result.pop();
            if (tmp == "亿" && result.top() == "万") result.pop();
            word_.append(tmp);
        }
        if (point_pos == -1)    word_.append("元整");
        else{
            word_.append("元");
            for (int i = 0; i < part_dec.size(); ++i){
                word_.append(digits_[int(part_dec[i]) - 48]);
                word_.append(unit_2[i]);
            }
        }
    }
    string num2uper(int n)
    {
        if (n < 0 || n>9) cerr << "输入错误" << endl;
        else return this->digits_[n];
    }
};
string Num2Uper::digits_[10] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
string Num2Uper::unit_1[13] = { "", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟","万" };
string Num2Uper::unit_2[2] = { "角", "分" };
string digits[10] = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
string unit1[13] = { "", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿", "拾", "佰", "仟","万" };
string unit2[2] = { "角", "分" };


//大写转数字
string Transform(string input)
{
    string copy_input = input;
    for (int i = 0; i < 13; i++) {
        int temp = 0;
        if (copy_input.find("零") != string::npos) copy_input = copy_input.replace(copy_input.find("零"), 2, "0");
        if (copy_input.find("壹") != string::npos) copy_input = copy_input.replace(copy_input.find("壹"), 2, "1");
        if (copy_input.find("贰") != string::npos) copy_input = copy_input.replace(copy_input.find("贰"), 2, "2");
        if (copy_input.find("叁") != string::npos) copy_input = copy_input.replace(copy_input.find("叁"), 2, "3");
        if (copy_input.find("肆") != string::npos) copy_input = copy_input.replace(copy_input.find("肆"), 2, "4");
        if (copy_input.find("伍") != string::npos) copy_input = copy_input.replace(copy_input.find("伍"), 2, "5");
        if (copy_input.find("陆") != string::npos) copy_input = copy_input.replace(copy_input.find("陆"), 2, "6");
        if (copy_input.find("柒") != string::npos) copy_input = copy_input.replace(copy_input.find("柒"), 2, "7");
        if (copy_input.find("捌") != string::npos) copy_input = copy_input.replace(copy_input.find("捌"), 2, "8");
        if (copy_input.find("玖") != string::npos) copy_input = copy_input.replace(copy_input.find("玖"), 2, "9");
    }
    if (copy_input.find("元整") != string::npos) copy_input = copy_input.erase(copy_input.find("元整"), 4);
    if (copy_input.rfind('亿') == copy_input.length() - 1) copy_input = copy_input + "00000000";
    if (copy_input.rfind('万') == copy_input.length() - 1) copy_input = copy_input + "0000";
    if (copy_input.rfind('百') == copy_input.length() - 1) copy_input = copy_input + "00";
    if (copy_input.rfind('十') == copy_input.length() - 1) copy_input = copy_input + "0";

    if (copy_input.find("亿") != string::npos) copy_input = copy_input.erase(copy_input.find("亿"), 2);
    if (copy_input.find("万") != string::npos) copy_input = copy_input.erase(copy_input.find("万"), 2);

    for (int i = 0; i < 5; i++) {
        int temp = 0;
        if (copy_input.find("佰") != string::npos) copy_input = copy_input.erase(copy_input.find("佰"), 2);
        if (copy_input.find("仟") != string::npos) copy_input = copy_input.erase(copy_input.find("仟"), 2);
        if (copy_input.find("拾") != string::npos) copy_input = copy_input.erase(copy_input.find("拾"), 2);
    }
    return copy_input;

}



int main(int argc, const char **argv)
{
    string str;
    cout << "***************************" << endl;
    cout << "       数字转换系统" << endl;
    cout << "***************************" << endl;
    cout << "1.数字转大写;" << endl;
    cout << "2.大写转数字" << endl;
    cout << "0.exit" << endl;
    cout << "选择转换模式:" << endl;
    int x;
    while (cin >> x) {
        switch (x) {
            case 0:return 0;
            case 1: {
                cout << "请输入金额：" << endl;
                cin >> str;
                if (str == "-1" || str[0] < '0' || str[0] > '9') {
                    cout << "输入错误" << endl;
                    cout << "选择转换模式:" << endl;
                    break;
                }
                Num2Uper num = Num2Uper(str);
                num.transform();
                cout << num.getWord() << endl;
                cout << "选择转换模式:" << endl;
            }break;
            case 2: {
                cout << "请输入金额：" << endl;
                cin >> str;
                if (str == "-1") break;
   
                cout << Transform(str) <<endl;
                cout << "选择转换模式:" << endl;
            }break;
        }
    }
    
    return 0;
}