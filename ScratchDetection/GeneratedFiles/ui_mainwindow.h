/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imgview.h"
#include "logviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionExit;
    QAction *actionOpen_Camera;
    QAction *actionClose_Camera;
    QAction *actionSingle_Shot;
    QAction *actionContinuous_Shot;
    QAction *actionStop;
    QAction *actionPause;
    QAction *actionBackGround;
    QAction *actionSaving_Image;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QTabWidget *tabImageView;
    QWidget *ImageEditing;
    QGridLayout *gridLayout_4;
    QScrollArea *ScrollArea_Image_View;
    QWidget *scrollAreaWidgetContents;
    QWidget *DecfecCharacters;
    QGridLayout *gridLayout_7;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;
    LogViewer *plainTextEdit;
    QTabWidget *tabThresholdProcessing;
    QWidget *Advanced;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpinBox *spinBox;
    QLabel *label;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;
    ImgView *lbMainImage_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuCamera;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1313, 635);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOpen_Camera = new QAction(MainWindowClass);
        actionOpen_Camera->setObjectName(QStringLiteral("actionOpen_Camera"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icon/black-connected-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Camera->setIcon(icon);
        actionClose_Camera = new QAction(MainWindowClass);
        actionClose_Camera->setObjectName(QStringLiteral("actionClose_Camera"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icon/black-disconnected-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_Camera->setIcon(icon1);
        actionSingle_Shot = new QAction(MainWindowClass);
        actionSingle_Shot->setObjectName(QStringLiteral("actionSingle_Shot"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icon/black-stack-of-photos-24 - Copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSingle_Shot->setIcon(icon2);
        actionContinuous_Shot = new QAction(MainWindowClass);
        actionContinuous_Shot->setObjectName(QStringLiteral("actionContinuous_Shot"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icon/black-stack-of-photos-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContinuous_Shot->setIcon(icon3);
        actionStop = new QAction(MainWindowClass);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icon/black-stop-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon4);
        actionPause = new QAction(MainWindowClass);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icon/black-pause-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon5);
        actionBackGround = new QAction(MainWindowClass);
        actionBackGround->setObjectName(QStringLiteral("actionBackGround"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icon/background.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackGround->setIcon(icon6);
        actionSaving_Image = new QAction(MainWindowClass);
        actionSaving_Image->setObjectName(QStringLiteral("actionSaving_Image"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icon/save-icon-5412.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaving_Image->setIcon(icon7);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        tabImageView = new QTabWidget(centralWidget);
        tabImageView->setObjectName(QStringLiteral("tabImageView"));
        ImageEditing = new QWidget();
        ImageEditing->setObjectName(QStringLiteral("ImageEditing"));
        gridLayout_4 = new QGridLayout(ImageEditing);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        ScrollArea_Image_View = new QScrollArea(ImageEditing);
        ScrollArea_Image_View->setObjectName(QStringLiteral("ScrollArea_Image_View"));
        ScrollArea_Image_View->setMinimumSize(QSize(400, 0));
        ScrollArea_Image_View->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        ScrollArea_Image_View->setMouseTracking(true);
        ScrollArea_Image_View->setFocusPolicy(Qt::NoFocus);
        ScrollArea_Image_View->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1061, 368));
        ScrollArea_Image_View->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(ScrollArea_Image_View, 0, 0, 1, 1);

        tabImageView->addTab(ImageEditing, QString());
        DecfecCharacters = new QWidget();
        DecfecCharacters->setObjectName(QStringLiteral("DecfecCharacters"));
        gridLayout_7 = new QGridLayout(DecfecCharacters);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        graphicsView = new QGraphicsView(DecfecCharacters);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_7->addWidget(graphicsView, 0, 0, 1, 1);

        tabImageView->addTab(DecfecCharacters, QString());

        gridLayout_5->addWidget(tabImageView, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(200, 16777215));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        plainTextEdit = new LogViewer(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(plainTextEdit);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox, 0, 1, 1, 1);

        tabThresholdProcessing = new QTabWidget(centralWidget);
        tabThresholdProcessing->setObjectName(QStringLiteral("tabThresholdProcessing"));
        tabThresholdProcessing->setMinimumSize(QSize(400, 0));
        tabThresholdProcessing->setMaximumSize(QSize(16777215, 120));
        Advanced = new QWidget();
        Advanced->setObjectName(QStringLiteral("Advanced"));
        horizontalLayout_3 = new QHBoxLayout(Advanced);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_2 = new QGroupBox(Advanced);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        spinBox = new QSpinBox(groupBox_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(255);
        spinBox->setValue(255);

        gridLayout->addWidget(spinBox, 1, 1, 1, 2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(255);

        gridLayout->addWidget(spinBox_2, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_2);

        horizontalSpacer_2 = new QSpacerItem(925, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        tabThresholdProcessing->addTab(Advanced, QString());
        groupBox_2->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabThresholdProcessing->addTab(tab_2, QString());

        gridLayout_5->addWidget(tabThresholdProcessing, 1, 0, 1, 1);

        lbMainImage_4 = new ImgView(centralWidget);
        lbMainImage_4->setObjectName(QStringLiteral("lbMainImage_4"));
        lbMainImage_4->setMinimumSize(QSize(80, 80));
        lbMainImage_4->setMaximumSize(QSize(400, 200));
        lbMainImage_4->setAutoFillBackground(true);
        lbMainImage_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lbMainImage_4, 1, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMouseTracking(true);
        mainToolBar->setFocusPolicy(Qt::StrongFocus);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1313, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuCamera = new QMenu(menuBar);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        MainWindowClass->setMenuBar(menuBar);

        mainToolBar->addAction(actionOpen_Camera);
        mainToolBar->addAction(actionSaving_Image);
        mainToolBar->addAction(actionClose_Camera);
        mainToolBar->addAction(actionSingle_Shot);
        mainToolBar->addAction(actionContinuous_Shot);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionBackGround);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuCamera->menuAction());
        menuFile->addAction(actionExit);
        menuCamera->addAction(actionOpen_Camera);
        menuCamera->addAction(actionClose_Camera);
        menuCamera->addAction(actionSingle_Shot);
        menuCamera->addAction(actionContinuous_Shot);
        menuCamera->addAction(actionStop);
        menuCamera->addAction(actionPause);

        retranslateUi(MainWindowClass);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindowClass, SLOT(close()));

        tabImageView->setCurrentIndex(0);
        tabThresholdProcessing->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+E", 0));
        actionOpen_Camera->setText(QApplication::translate("MainWindowClass", "Open Camera", 0));
#ifndef QT_NO_WHATSTHIS
        actionOpen_Camera->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionOpen_Camera->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+O", 0));
        actionClose_Camera->setText(QApplication::translate("MainWindowClass", "Close Camera", 0));
        actionClose_Camera->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+L", 0));
        actionSingle_Shot->setText(QApplication::translate("MainWindowClass", "Single Shot", 0));
        actionSingle_Shot->setShortcut(QApplication::translate("MainWindowClass", "F6", 0));
        actionContinuous_Shot->setText(QApplication::translate("MainWindowClass", "Continuous Shot", 0));
        actionContinuous_Shot->setShortcut(QApplication::translate("MainWindowClass", "F7", 0));
        actionStop->setText(QApplication::translate("MainWindowClass", "Stop", 0));
#ifndef QT_NO_WHATSTHIS
        actionStop->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        actionStop->setShortcut(QApplication::translate("MainWindowClass", "F8", 0));
        actionPause->setText(QApplication::translate("MainWindowClass", "Pause", 0));
        actionPause->setShortcut(QApplication::translate("MainWindowClass", "F9", 0));
        actionBackGround->setText(QApplication::translate("MainWindowClass", "BackGround", 0));
        actionSaving_Image->setText(QApplication::translate("MainWindowClass", "Saving Image", 0));
        tabImageView->setTabText(tabImageView->indexOf(ImageEditing), QApplication::translate("MainWindowClass", "Edit Character Set File", 0));
        tabImageView->setTabText(tabImageView->indexOf(DecfecCharacters), QApplication::translate("MainWindowClass", "Decfect Characterization", 0));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Control Panel", 0));
        pushButton->setText(QApplication::translate("MainWindowClass", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MainWindowClass", "PushButton", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindowClass", "Threshold Limits", 0));
        label->setText(QApplication::translate("MainWindowClass", "Upper", 0));
        label_2->setText(QApplication::translate("MainWindowClass", "Lower Value", 0));
        tabThresholdProcessing->setTabText(tabThresholdProcessing->indexOf(Advanced), QApplication::translate("MainWindowClass", "Advanced Threshold", 0));
        tabThresholdProcessing->setTabText(tabThresholdProcessing->indexOf(tab_2), QApplication::translate("MainWindowClass", "Tab 2", 0));
        lbMainImage_4->setText(QApplication::translate("MainWindowClass", "Product 1", 0));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0));
        menuView->setTitle(QApplication::translate("MainWindowClass", "View", 0));
        menuCamera->setTitle(QApplication::translate("MainWindowClass", "Camera", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
