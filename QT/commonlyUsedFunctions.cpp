//sleep函数
#include<QTime>
void sleep(unsigned int msec);
void MainWindow::sleep(unsigned int msec){
    QTime reachTime =QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

//弹框显示信息
#include<QMessageBox>
void showMessage(QString text);
void MainWindow::showMessage(QString text){//传入待提示的文字
    QMessageBox* mbox=new QMessageBox();
    mbox->setText(text);
    mbox->setWindowTitle("提示");
    mbox->show();
}
