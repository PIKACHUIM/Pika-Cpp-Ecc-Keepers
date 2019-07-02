#ifndef MAIN_CPP
#define MAIN_CPP
#include "./UIPF/mainwidget.h"
int main(int argc, char *argv[])
{
    QApplication MAIN_APPL(argc, argv);//创建程序
      MainWidget MAIN_WIND;            //创建窗体
                 MAIN_WIND.show();     //显示窗口
          return MAIN_APPL.exec();     //执行渲染
}
#endif
