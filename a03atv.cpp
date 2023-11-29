#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Criação da janela principal
    QWidget window;
    window.setWindowTitle("Exemplo de Interface");
    window.setGeometry(100, 100, 400, 200);

    // Layout principal
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // Campo de entrada de texto
    QLineEdit *lineEdit = new QLineEdit(&window);
    layout->addWidget(lineEdit);

    // Botão
    QPushButton *button = new QPushButton("Clique em mim", &window);
    layout->addWidget(button);

    // Conexão do botão a uma função
    QObject::connect(button, &QPushButton::clicked, [&]() {
        QString texto = lineEdit->text();
        qDebug() << "Texto digitado: " << texto;
    });

    // Exibição da janela
    window.show();

    // Execução do loop de eventos
    return app.exec();
}
