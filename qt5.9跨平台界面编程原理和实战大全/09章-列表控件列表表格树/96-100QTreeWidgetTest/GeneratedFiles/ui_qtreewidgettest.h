/********************************************************************************
** Form generated from reading UI file 'qtreewidgettest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTREEWIDGETTEST_H
#define UI_QTREEWIDGETTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTreeWidgetTestClass
{
public:
    QTreeWidget *treeWidget;

    void setupUi(QWidget *QTreeWidgetTestClass)
    {
        if (QTreeWidgetTestClass->objectName().isEmpty())
            QTreeWidgetTestClass->setObjectName(QStringLiteral("QTreeWidgetTestClass"));
        QTreeWidgetTestClass->resize(1094, 744);
        treeWidget = new QTreeWidget(QTreeWidgetTestClass);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(0, 50, 1081, 661));
        treeWidget->setStyleSheet(QLatin1String("QTreeWidget{\n"
"	background-color: #FEFFF7;\n"
"	alternate-background-color: #CBE8D9;\n"
"}\n"
"\n"
"QTreeWidget::item:hover{\n"
"	background-color: #C5DAFF;\n"
"}\n"
"\n"
"QTreeWidget::item:selected{\n"
"	background-color: #DEBBE8;\n"
"}\n"
"QTreeWidget::branch{\n"
"	\n"
"	/*background-color: rgb(65, 48, 255);*/\n"
"}\n"
"\n"
" QTreeView::branch:has-siblings:!adjoins-item {\n"
"      border-image: url(vline.png) 0;\n"
"  }\n"
"  QTreeView::branch:has-siblings:adjoins-item {\n"
"      border-image: url(branch-more.png) 0;\n"
"  }\n"
"  QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"      border-image: url(branch-end.png) 0;\n"
"  }\n"
"  QTreeView::branch:has-children:!has-siblings:closed,\n"
"  QTreeView::branch:closed:has-children:has-siblings {\n"
"          border-image: none; image: url(branch-closed.png);\n"
"  }\n"
"  QTreeView::branch:open:has-children:!has-siblings,\n"
"  QTreeView::branch:open:has-children:has-siblings  {\n"
"          border-image: none;\n"
"          image: url(b"
                        "ranch-open.png);\n"
"  }\n"
"QHeaderView::section{\n"
"	\n"
"	background-color:  #FFE0D8;\n"
"	border:1px solid #C5DAFF;\n"
"\n"
"}\n"
"\n"
""));
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setSortingEnabled(true);
        treeWidget->setAnimated(true);
        treeWidget->header()->setVisible(true);
        treeWidget->header()->setDefaultSectionSize(200);

        retranslateUi(QTreeWidgetTestClass);
        QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), QTreeWidgetTestClass, SLOT(Click(QTreeWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), QTreeWidgetTestClass, SLOT(Double(QTreeWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(itemEntered(QTreeWidgetItem*,int)), QTreeWidgetTestClass, SLOT(Hover(QTreeWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(itemExpanded(QTreeWidgetItem*)), QTreeWidgetTestClass, SLOT(Expand(QTreeWidgetItem*)));

        QMetaObject::connectSlotsByName(QTreeWidgetTestClass);
    } // setupUi

    void retranslateUi(QWidget *QTreeWidgetTestClass)
    {
        QTreeWidgetTestClass->setWindowTitle(QApplication::translate("QTreeWidgetTestClass", "QTreeWidgetTest", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\210\2273", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\210\2272", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\210\2271", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("QTreeWidgetTestClass", "ss ", Q_NULLPTR));
        ___qtreewidgetitem1->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\351\241\271\347\233\2564", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\351\241\271\347\233\2563", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem6->child(0);
        ___qtreewidgetitem7->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem8->setText(1, QApplication::translate("QTreeWidgetTestClass", "1", Q_NULLPTR));
        ___qtreewidgetitem8->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\351\241\271\347\233\2562", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem9->setText(2, QApplication::translate("QTreeWidgetTestClass", "123123", Q_NULLPTR));
        ___qtreewidgetitem9->setText(1, QApplication::translate("QTreeWidgetTestClass", "12312", Q_NULLPTR));
        ___qtreewidgetitem9->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\351\241\271\347\233\2561", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem10 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem10->setText(2, QApplication::translate("QTreeWidgetTestClass", "23", Q_NULLPTR));
        ___qtreewidgetitem10->setText(1, QApplication::translate("QTreeWidgetTestClass", "22", Q_NULLPTR));
        ___qtreewidgetitem10->setText(0, QApplication::translate("QTreeWidgetTestClass", "21", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem10->child(0);
        ___qtreewidgetitem11->setText(2, QApplication::translate("QTreeWidgetTestClass", "32", Q_NULLPTR));
        ___qtreewidgetitem11->setText(1, QApplication::translate("QTreeWidgetTestClass", "31", Q_NULLPTR));
        ___qtreewidgetitem11->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\2561", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem11->child(0);
        ___qtreewidgetitem12->setText(2, QApplication::translate("QTreeWidgetTestClass", "43", Q_NULLPTR));
        ___qtreewidgetitem12->setText(1, QApplication::translate("QTreeWidgetTestClass", "41", Q_NULLPTR));
        ___qtreewidgetitem12->setText(0, QApplication::translate("QTreeWidgetTestClass", "\346\226\260\345\273\272\345\255\220\351\241\271\347\233\256", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem13->setText(2, QApplication::translate("QTreeWidgetTestClass", "13", Q_NULLPTR));
        ___qtreewidgetitem13->setText(1, QApplication::translate("QTreeWidgetTestClass", "12", Q_NULLPTR));
        ___qtreewidgetitem13->setText(0, QApplication::translate("QTreeWidgetTestClass", "11", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class QTreeWidgetTestClass: public Ui_QTreeWidgetTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTREEWIDGETTEST_H
