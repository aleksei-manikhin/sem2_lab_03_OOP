#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAbstractButton>
#include <QButtonGroup>
#include <QKeySequence>
#include <QList>
#include <QShortcut>
#include <QString>
#include <QStyle>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
    setupKeyboardShortcuts();
    ui->displayLine->setText(QString::fromStdString(facade.getDisplayText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections() {
    QButtonGroup* buttonGroup = new QButtonGroup(this);
    const QList<QAbstractButton*> buttons = findChildren<QAbstractButton*>();

    for (QAbstractButton* button : buttons) {
        buttonGroup->addButton(button);
    }

    connect(buttonGroup, QOverload<QAbstractButton*>::of(&QButtonGroup::buttonClicked),
            this, [this](QAbstractButton* button) {
        handleAction(button->text().toStdString());
    });
}

void MainWindow::setupKeyboardShortcuts() {
    const QString allowedSymbols = "0123456789.+-*/()=";

    for (QChar symbol : allowedSymbols) {
        std::string action = QString(symbol).toStdString();
        addShortcut(QKeySequence(QString(symbol)), action);
    }

    addShortcut(QKeySequence(Qt::Key_Return), "=");
    addShortcut(QKeySequence(Qt::Key_Enter), "=");
    addShortcut(QKeySequence(Qt::Key_Backspace), "Del");
}

void MainWindow::addShortcut(const QKeySequence& keySequence, const std::string& action) {
    QShortcut* shortcut = new QShortcut(keySequence, this);

    connect(shortcut, &QShortcut::activated, this, [this, action]() {
        handleAction(action);
    });
}

void MainWindow::handleAction(const std::string& action) {
    FacadeOperationResult result = facade.pressAction(action);
    updateDisplay(result);
}

void MainWindow::updateDisplay(const FacadeOperationResult& result) {
    setErrorState(!result.isSuccess());

    if (result.isSuccess()) {
        ui->displayLine->setText(QString::fromStdString(result.getDisplayText()));
        return;
    }

    showError(result.getErrorMessage());
}

void MainWindow::showError(const std::string& message) {
    ui->displayLine->setText(QString::fromStdString(message));
}

void MainWindow::setErrorState(bool isError) {
    ui->displayFrame->setProperty("error", isError);
    ui->displayLine->setProperty("error", isError);

    refreshStyle(ui->displayFrame);
    refreshStyle(ui->displayLine);
}

void MainWindow::refreshStyle(QWidget* widget) {
    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
}
