#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Cria��o da janela principal
    QWidget window;
    window.setWindowTitle("Exemplo de Interface");
    window.setGeometry(100, 100, 400, 200);

    // Layout principal
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Campo de entrada de texto
    QLineEdit *lineEdit = new QLineEdit(&window);
    layout->addWidget(lineEdit);

    // Bot�o
    QPushButton *button = new QPushButton("Clique em mim", &window);
    layout->addWidget(button);

    // Conex�o do bot�o a uma fun��o
    QObject::connect(button, &QPushButton::clicked, [&]() {
        QString texto = lineEdit->text();
        qDebug() << "Texto digitado: " << texto;
    });

    // Exibi��o da janela
    window.show();

    // Execu��o do loop de eventos
    return app.exec();
}
