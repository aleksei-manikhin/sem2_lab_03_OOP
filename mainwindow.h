#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "facade.h"
#include "facadeOperationResult.h"

#include <QMainWindow>

#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class QWidget;
class QKeySequence;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Facade facade;

    void setupConnections();
    void setupKeyboardShortcuts();
    void addShortcut(const QKeySequence& keySequence, const std::string& action);
    void handleAction(const std::string& action);
    void updateDisplay(const FacadeOperationResult& result);
    void showError(const std::string& message);
    void setErrorState(bool isError);
    void refreshStyle(QWidget* widget);
};
#endif // MAINWINDOW_H
