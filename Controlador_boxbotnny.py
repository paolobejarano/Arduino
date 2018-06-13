from tkinter import *

class Application(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.grid()
        self.create_widgets()

    def create_widgets(self):
        self.texto = Label(self, text = "Boxbotnny")
        self.texto.grid()

        self.boton1 = Button(self, text = "Traer caja", height=1, width=15)
        self.boton1.grid()

        self.boton2 = Button(self, text = "Devolver caja", height=1, width=15)
        self.boton2.grid()

        self.boton3 = Button(self, text = "Poner en reposo", height=1, width=15)
        self.boton3.grid()

root = Tk()
root.title("Controlador de robot")
root.geometry("500x300")
app = Application(root)
root.mainloop()
