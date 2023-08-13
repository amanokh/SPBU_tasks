using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace Project5_1
{
    public partial class Form1 : Form
    {
        enum ButtonState
        {
            Question,
            Results,
            Close
        }
        ButtonState buttonState;
        public XmlReader reader;
        public XmlReader readerLevel;
        public string filePath;
        public string fileName;
        public int score;
        public int answer;
        public int correctAnswer;
        public int qNumber;
        public Form1(string[] args)
        {
            InitializeComponent();
            if (args.Length > 0)
            {
                score = 0;
                correctAnswer = -1;
                qNumber = 0;

                filePath = Application.StartupPath + "\\";
                fileName = args[0];
                try
                {
                    reader = XmlReader.Create(filePath + fileName);
                    if (reader.ReadToFollowing("head"))
                        this.Text = reader.ReadElementContentAsString();
                    if (reader.ReadToFollowing("descr"))
                        label1.Text = reader.ReadElementContentAsString();
                    readerLevel = XmlReader.Create(filePath + fileName);
                }
                catch
                {
                    label1.Text = "Ошибка доступа к файлу " + filePath + fileName;
                    buttonState = ButtonState.Close;
                }
            }
            else
            {
                label1.Text =
                    "Файл теста необходимо указать в команде запуска программы.\n Например: 'exam economics.xml' или 'exam c:\\spb.xml'.";
                buttonState = ButtonState.Close;
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            RadioButton[] buttons = { radioButton1, radioButton2, radioButton3, radioButton4, radioButton5, radioButton6 };

            switch (buttonState)
            {
                case ButtonState.Question:
                    if (answer == correctAnswer)
                    {
                        score++;
                    }

                    if (reader.ReadToFollowing("q"))
                    {
                        label2.Text = "Вопрос " + ++qNumber;


                        for (int j = 0; j < 6; ++j)
                        {
                            buttons[j].Visible = true;
                            buttons[j].Checked = false;
                        }

                        button1.Enabled = false;
                        try
                        {
                            string a;
                            label1.Text = reader.GetAttribute("text");
                            if (reader.GetAttribute("src") != null)
                            {
                                pictureBox1.Visible = true;
                                pictureBox1.Image = new Bitmap(reader.GetAttribute("src"));
                            }
                            else
                            {
                                pictureBox1.Visible = false;
                            }

                            int i = 0;
                            reader.ReadToFollowing("a");
                            do
                            {
                                if (reader.GetAttribute("correct") == "yes")
                                {
                                    correctAnswer = i;
                                }
                                a = reader.ReadElementContentAsString();
                                buttons[i].Text = a;
                           
                                ++i;
                            }
                            while (reader.ReadToNextSibling("a"));

                            for (int j = i; j < 6; ++j)
                                buttons[j].Visible = false;
                        }
                        catch
                        {
                            label2.Text = "Ошибка чтения .xml файла";
                        }
                    }
                    else
                    {
                        buttonState = ButtonState.Results;
                        button1_Click(sender, e);
                    }

                    break;
                case ButtonState.Results:
                    for (int j = 0; j < 6; ++j)
                        buttons[j].Visible = false;
                    pictureBox1.Visible = false;
                    label2.Visible = false;

                    string text = String.Empty;
                    while (readerLevel.ReadToFollowing("level"))
                    {
                        if (score >= Convert.ToInt32(readerLevel.GetAttribute("score")))
                        {
                            text = readerLevel.GetAttribute("text");
                            break;
                        }
                    }

                    label1.Text = "Тестирование завершено.\n" + "Всего вопросов: " + qNumber + ". " +
                          "Правильных ответов: " + score + ".\n" +
                          text;
                    buttonState = ButtonState.Close;
                    break;
                case ButtonState.Close:
                    Close();
                    break;
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;
            if (rb.Checked) answer = Convert.ToInt32(rb.Tag);
            button1.Enabled = true;
        }
    }
}
