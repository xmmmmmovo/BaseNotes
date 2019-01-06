#include <iostream>
#include <string>
#include <chrono>
#include <windows.h>
#include <ctime>

using namespace std;



class Timer {
public:
 
    explicit Timer() {
        _name = "Time elapsed:";
        restart();
    }
 
    explicit Timer(const std::string &name) {
        _name = name + ":";
        restart();
    }
 
    /**
    * ������ʱ
    */
    inline void restart() {
        _start_time = std::chrono::steady_clock::now();
    }
 
    /**
    * ������ʱ
    * @return ����ms��
    */
    inline double elapsed(bool restart = false) {
        _end_time = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = _end_time-_start_time;
        if(restart)
            this->restart();
        return diff.count()*1000;
    }
 
    /**
     * ��ӡʱ�䲢������ʱ��
     * @param tip ��ʾ
     */
    void rlog(const std::string &tip){
        log(true,tip,true,false);
    }
 
    /**
    * ��ӡʱ��
    * @param reset ���֮���Ƿ�������ʱ����true������false������
    * @param unit_ms true��ms��false��s
    * @param tip �����ʾ
    * @param kill ���֮���Ƿ��˳�����true�˳���false���˳�
    */
    void log(bool reset = false, const std::string &tip = "",
             bool unit_ms = true, bool kill = false
    ) {
        if (unit_ms) {
            if (tip.length() > 0)
                std::cout << tip+":" << elapsed() << "ms" << std::endl;
            else
                std::cout << _name << elapsed() << "ms" << std::endl;
        } else {
            if (tip.length() > 0)
                std::cout << tip+":" << elapsed() / 1000.0 << "s" << std::endl;
            else
                std::cout << _name << elapsed() / 1000.0 << "s" << std::endl;
        }
 
        if (reset)
            this->restart();
 
        if (kill)
            exit(5);
    }
 
 
private:
    std::chrono::steady_clock::time_point _start_time;
    std::chrono::steady_clock::time_point _end_time;
    std::string _name;
};


int main(int argc, char const *argv[])
{
    Timer timer;
    std::cout << "Hello, World!" << std::endl;
    std::cout<<timer.elapsed()<<std::endl;
    timer.restart();
    system("pause");
    return 0;
}
