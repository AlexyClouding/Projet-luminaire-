from PyQt5 import QtWidgets
from monFichier import Ui_MainWindow
import sys

class ApplicationIHM(QtWidgets.QMainWindow):
    def __init__(self):
        super(ApplicationIHM, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)


    def bouton_go(self):
        self.ui.text.setText('Bonjour')

    def text_change(self):
        self.ui.text.setText(self.ui.text_box.text())


def main():
    app = QtWidgets.QApplication(sys.argv)
    application = ApplicationIHM()
    application.show()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()