import sys
from PyQt6 import QtWidgets, uic

# Hard coded Python for storing student entries
data = [["Ahmed", "4289", "CS", 3.85],
        ["Hammad", "4305", "CS", 3.53],
        ["Mohsin", "4333", "CS", 3.92]]

class MainForm(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        uic.loadUi("main_form.ui", self)

        # Populate combo box
        self.id_combo.addItems([i[1] for i in data])
        self.name_input.setText(data[0][0])

        # Connect signals
        self.submit_button.clicked.connect(self.open_view_form)
        self.id_combo.activated.connect(self.handle_id_toggle)

    def open_view_form(self):
        index = self.id_combo.currentIndex()
        student_id, name, major, gpa = data[index][1], data[index][0], data[index][2], data[index][3]

        self.view_form = ViewForm(student_id, name, major, gpa)
        self.view_form.show()

    def handle_id_toggle(self):
        index = self.id_combo.currentIndex()
        self.name_input.setText(data[index][0])

class ViewForm(QtWidgets.QMainWindow):
    def __init__(self, student_id, name, major, gpa):
        super().__init__()
        uic.loadUi("view_form.ui", self)

        # Fill fields
        self.id_input.setText(student_id)
        self.id_input.setDisabled(True)
        self.name_input.setText(name)
        self.name_input.setDisabled(True)
        self.major_input.setText(major)
        self.major_input.setDisabled(True)
        self.gpa_input.setText(str(gpa))
        self.gpa_input.setDisabled(True)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MainForm()
    window.show()
    sys.exit(app.exec())
