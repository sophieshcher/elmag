import tkinter as tk

class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Counter")
        self.text = tk.Text(self, width=50, height=10, font=('Times New Roman', 10))
        self.text.pack(pady=10, padx=10)

        btn_frame = tk.Frame(self)
        btn_frame.pack(pady=10)

        self.btn_clear = tk.Button(btn_frame, text="Clear", width=10, command=self.clear_text)
        self.btn_clear.grid(row=0, column=0, padx=5)

        self.btn_count = tk.Button(btn_frame, text="Count", width=10, command=self.count)
        self.btn_count.grid(row=0, column=1, padx=5)

        self.btn_goodbye = tk.Button(btn_frame, text="Goodbye", width=10,bg="red", command=self.goodbye)
        self.btn_goodbye.grid(row=0, column=2, padx=5)

        self.result_label = tk.Label(self, text="", font=('Arial', 12), fg='black')
        self.result_label.pack(pady=10)

    def clear_text(self):
        self.text.delete("1.0", tk.END)
        self.result_label.config(text="")

    def count(self):
        text = self.text.get("1.0", tk.END).upper()
        count_a = text.count('A')
        count_t = text.count('T')
        count_c = text.count('C')
        count_g = text.count('G')

        result = f"A: {count_a}  T: {count_t}  C: {count_c}  G: {count_g}"
        self.result_label.config(text=result)

    def goodbye(self):
        self.destroy()

if __name__ == "__main__":
    app = App()
    app.mainloop()


