from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget
import sys



def applicationpyQt():

    def bouton_go():
        text.setText('Bonjour')
    def text_change():
        text.setText(text_box.text())

    app = QApplication(sys.argv)
    windows = QWidget()
    windows.setGeometry(50, 50, 500, 300)
    windows.setWindowTitle('PyQt')

    text = QtWidgets.QLabel(windows)
    text.setText("Vive la NSI!")
    text.move(225, 125)

    button = QtWidgets.QPushButton("Go", windows)
    button.move(225,150)
    button.clicked.connect(bouton_go)

    text_box = QtWidgets.QLineEdit(windows)
    text_box.resize(200,20)
    text_box.move(225,200)
    text_box.textChanged.connect(text_change)


    windows.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    applicationpyQt()


