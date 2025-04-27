#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSysInfo>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "pathselectiondialog.h"
#include "mainwindow.h"

void createFoldersAndFile(const QString &selectedPath) {
    // Set base folder path
    QString baseFolderPath = selectedPath + "/StudentManagement";

    // Create the base folder
    QDir baseDir(baseFolderPath);
    if (!baseDir.exists()) {
        baseDir.mkpath(".");
    }

    // Create subfolders
    QStringList subfolders;
    subfolders << "users/student" << "users/teacher" << "courses";

    foreach (const QString &folder, subfolders) {
        QDir subDir(baseDir.absolutePath() + "/" + folder);
        if (!subDir.exists()) {
            subDir.mkpath(".");
        }
    }

    // Create and write to file
    QFile file(baseFolderPath + "/0000000001.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "This is a sample text written to the file.";
        file.close();
        qDebug() << "File created and written successfully.";
    } else {
        qDebug() << "Error creating or writing to the file.";
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Check if it's the first run of the application
    QSettings settings;
    bool isFirstRun = !settings.contains("firstRun");

    // Show path selection dialog if it's the first run
    if (isFirstRun) {
        PathSelectionDialog dialog;
        if (dialog.exec() == QDialog::Accepted) {
            QString selectedPath = dialog.getSelectedPath();
            QMessageBox::information(nullptr, "Welcome", "Thanks for choosing our application!\nPlease read the documentation provided with the application.");
            createFoldersAndFile(selectedPath);
            settings.setValue("dataPath", selectedPath);
            settings.setValue("firstRun", false); // Set firstRun flag to false
        } else {
            // Handle if user cancels path selection
            QMessageBox::critical(nullptr, "Error", "Path selection canceled. The application will now exit.");
            return 1; // Exit application
        }
    }

    // Proceed with the main application logic
    // Use the stored dataPath for storing data
    MainWindow w;
    w.show();
    return a.exec();
}
