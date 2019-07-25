#include <QApplication>

#include "Calculator.h"

char ButtonChar[16][2] = {
                "1", "2", "3", "C",
                "4", "5", "6", "+",
                "7", "8", "9", "-",
                "0", "=", "X", "/",
};

Calculator::Calculator(QWidget* parent) : QWidget(parent)
{
        int i;
        flag = 0;
        operate = 0;

        resize(250, 150);

        QBoxLayout *vboxlayout = new QVBoxLayout(this);
        vboxlayout->setMargin(10);

        m_OutLabel = new QLabel(this);
        m_OutLabel->setText("0");
        m_OutLabel->setAlignment(Qt::AlignRight);
        m_OutLabel->setFrameShape(QFrame::Box);
        vboxlayout->addWidget(m_OutLabel);

        QGridLayout *grid = new QGridLayout();
        for(i = 0; i < 16; i++) {
                pushbutton[i] = new QPushButton(ButtonChar[i], this);
                grid->addWidget(pushbutton[i], i/4, i%4);
        }; 

        vboxlayout->addLayout(grid);

        QObject::connect(pushbutton[0], SIGNAL(clicked() ), SLOT( click_0() ));
        QObject::connect(pushbutton[1], SIGNAL(clicked() ), SLOT( click_1() ));
        QObject::connect(pushbutton[2], SIGNAL(clicked() ), SLOT( click_2() ));
        QObject::connect(pushbutton[3], SIGNAL(clicked() ), SLOT( click_3() ));
        QObject::connect(pushbutton[4], SIGNAL(clicked() ), SLOT( click_4() ));
        QObject::connect(pushbutton[5], SIGNAL(clicked() ), SLOT( click_5() ));
        QObject::connect(pushbutton[6], SIGNAL(clicked() ), SLOT( click_6() ));
        QObject::connect(pushbutton[7], SIGNAL(clicked() ), SLOT( click_7() ));
        QObject::connect(pushbutton[8], SIGNAL(clicked() ), SLOT( click_8() ));
        QObject::connect(pushbutton[9], SIGNAL(clicked() ), SLOT( click_9() ));
        QObject::connect(pushbutton[10], SIGNAL(clicked() ), SLOT( click_10() ));
        QObject::connect(pushbutton[11], SIGNAL(clicked() ), SLOT( click_11() ));
        QObject::connect(pushbutton[12], SIGNAL(clicked() ), SLOT( click_12() ));
        QObject::connect(pushbutton[13], SIGNAL(clicked() ), SLOT( click_13() ));
        QObject::connect(pushbutton[14], SIGNAL(clicked() ), SLOT( click_14() ));
        QObject::connect(pushbutton[15], SIGNAL(clicked() ), SLOT( click_15() ));
}

void Calculator::click_0()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+1);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_1()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+2);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_2()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+3);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_4()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+4);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_5()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+5);

        m_OutLabel->setText(number1);
        flag = 0;;
}

void Calculator::click_6()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+6);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_8()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+7);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_9()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+8);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_10()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+9);

        m_OutLabel->setText(number1);
        flag = 0;
}

void Calculator::click_12()
{
        float number = 0;

        if(!flag) number = m_OutLabel->text().toFloat()*10;
        number1.setNum(number+0);

        m_OutLabel->setText(number1);
        flag = 0;
}


void Calculator::click_7()
{
        if(number2.toFloat()) {
                number1.sprintf("%f", number2.toFloat() + m_OutLabel->text().toFloat());
                m_OutLabel->setText(number1);
        }
        number2 = number1;
        operate = flag = 1;
}


void Calculator::click_11()
{
        if(number2.toFloat()) {
                number1.sprintf("%f", number2.toFloat() - m_OutLabel->text().toFloat());
                m_OutLabel->setText(number1);
        }
        number2 = number1;
        operate = flag = 2;
}

void Calculator::click_14()
{
        if(number2.toFloat()) {
                number1.sprintf("%f", number2.toFloat() * m_OutLabel->text().toFloat());
                m_OutLabel->setText(number1);
        }

        number2 = number1;
        operate = flag = 3;
}

void Calculator::click_15()
{
        if(number2.toFloat()) {
                if(m_OutLabel->text().toFloat()) {
                        number1.sprintf("%f" ,number2.toFloat() / m_OutLabel->text().toFloat());
                        m_OutLabel->setText(number1);
                } else
                        m_OutLabel->setText("Error : Cannot Devide by Zero");
        }

        number2 = number1;
        operate = flag = 4;

}
                                                                                                
void Calculator::click_13()
{
        switch(operate) {
        case 1:
                number1.setNum(number2.toFloat() + m_OutLabel->text().toFloat());
                m_OutLabel->setText(number1);
                break;
        case 2:
                number1.setNum(number2.toFloat() - m_OutLabel->text().toFloat());
                m_OutLabel->setText(number1);
                break;
        case 3:
                number1.setNum(number2.toFloat() * m_OutLabel->text().toFloat());
                m_OutLabel->setText(number1);
                break;
        case 4:
                if(m_OutLabel->text().toFloat()) {
                        number1.setNum(number2.toFloat() / m_OutLabel->text().toFloat());
                        m_OutLabel->setText(number1);
                } else
                        m_OutLabel->setText("Error : Cannot Devide by Zero");
                break;
        };
        operate = 0;
        flag = 5;
        number1.setNum(0);
        number2.setNum(0);
}

void Calculator::click_3()
{
        operate = 0;
        flag = 1;
        number1.setNum(0);
        number2.setNum(0);
        m_OutLabel->setText("0");
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Calculator* calculator = new Calculator();
    calculator->show();

    return app.exec();
}
