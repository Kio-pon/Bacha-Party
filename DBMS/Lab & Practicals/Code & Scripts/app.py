# Import all the required libraries
from PyQt6 import QtWidgets , uic , QtGui , QtCore
import sys

class UI(QtWidgets.QMainWindow):
    def __init__(self):
    # Call the inherited classes __init__ method
        super(UI, self).__init__()
        # Load the .ui file
        uic.loadUi('hello world.ui', self )
        # Show the GUI
        self.show()
        # Event Handling
        self.clickMeButton.clicked.connect(self.handle_click)
    def handle_click(self):
        self.label.setText("Welcome to QT Designer")
    
    
app = QtWidgets.QApplication(sys.argv) # Create an instance of QtWidgets. QApplication
window = UI() # Create an instance of our class
app.exec() # Start the application