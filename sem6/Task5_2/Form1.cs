using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace Project5_2
{
    public partial class Form1 : Form
    {
        public List<double> d;

        public string header;
        public int N;
        public double[] dat;
        public double[] p;
        public string[] title;
        int width = 685;
        int height = 410;
        public Form1()
        {
            InitializeComponent();
            StreamReader sr;
            try
            {
                sr = new StreamReader(Application.StartupPath + "\\usd.dat");
                d = new List<double>();

                string t;
                while ((t = sr.ReadLine()) != null)
                {
                    if (t == "") break;
                    d.Add(Convert.ToDouble(t));
                }
                sr.Close();

                //tabPage1.Paint += new PaintEventHandler(drawDiagram);
                //tabPage2.Paint += new PaintEventHandler(drawGraph);
            }
            catch (FileNotFoundException ex)
            {
                MessageBox.Show(ex.Message + "\n" + "(" + ex.GetType() + ")", "График",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString(), "", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }

            try
            {
                Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
                sr = new StreamReader(Application.StartupPath + "\\date.dat",
                    Encoding.GetEncoding("windows-1251"));
                header = sr.ReadLine();
                N = Convert.ToInt16(sr.ReadLine());
                dat = new double[N];
                p = new double[N];
                title = new string[N];
                int i = 0;
                string st = sr.ReadLine();
                while (st != null && i < N)
                {
                    title[i] = st;
                    st = sr.ReadLine();
                    dat[i++] = Convert.ToDouble(st);
                    st = sr.ReadLine();
                }
                double sum = 0;
                int j;
                for (j = 0; j < N; j++)
                    sum += dat[j];
                for (j = 0; j < N; j++)
                    p[j] = dat[j] / sum;
                //tabPage3.Paint += drawPie;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Диаграмма", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void drawDiagram(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Font dFont = new Font("Tahoma", 9);
            Font hFont = new Font("Tahoma", 14, FontStyle.Regular);
            string header = "Изменение курса доллара";
            int wh = (int)g.MeasureString(header, hFont).Width;
            int x = (width - wh) / 2;
            g.DrawString(header, hFont, Brushes.DarkGreen, x, 5);

            double max = d[0];
            double min = d[0];
            for (int i = 1; i < d.Count; i++)
            {
                if (d[i] > max) max = d[i];
                if (d[i] < min) min = d[i];
            }

            int x1, y1;
            int w, h;

            w = (width - 40 - 5 * (d.Count - 1)) / d.Count;

            x1 = 20;
            for (int i = 0; i < d.Count; i++)
            {
                y1 = height - 20 -
                     (int)((height - 100) * (d[i] - min) /
                            (max - min));
                g.DrawString(Convert.ToString(d[i]), dFont, Brushes.Black, x1, y1 - 20);
                h = height - y1 - 20 + 1;
                g.FillRectangle(Brushes.ForestGreen, x1, y1, w, h);
                g.DrawRectangle(Pens.Black, x1, y1, w, h);
                x1 = x1 + w + 5;
            }
        }

        private void drawGraph(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Font dFont = new Font("Tahoma", 9);
            Font hFont = new Font("Tahoma", 14, FontStyle.Regular);
            string header = "Курс доллара";
            int wh = (int)g.MeasureString(header, hFont).Width;
            int x = (width - wh) / 2;
            g.DrawString(header, hFont, Brushes.Black, x, 5);

            int sw = (width - 40) / (d.Count - 1);
            double max = d[0];
            double min = d[0];
            for (int i = 1; i < d.Count; i++)
            {
                if (d[i] > max) max = d[i];
                if (d[i] < min) min = d[i];
            }

            int x1, y1, x2, y2;
            x1 = 20;
            y1 = height - 20 -
                 (int)((height - 100) * (d[0] - min) /
                        (max - min)
                 );
            g.DrawRectangle(Pens.Black, x1 - 2, y1 - 2, 4,
                4);
            g.DrawString(Convert.ToString(d[0]), dFont, Brushes.Black, x1 - 10, y1 - 20);

            for (int i = 1; i < d.Count; i++)
            {
                x2 = 8 + i * sw;
                y2 = height - 20 -
                     (int)((height - 100) * (d[i] - min) /
                            (max - min)
                     );
                g.DrawRectangle(Pens.Black, x2 - 2, y2 - 2, 4,
                    4);
                g.DrawLine(Pens.Black, x1, y1, x2,
                    y2);
                g.DrawString(Convert.ToString(d[i]), dFont, Brushes.Black, x2 - 10, y2 - 20);
                x1 = x2;
                y1 = y2;
            }
        }

        private void drawPie(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Font hFont = new Font("Tahoma", 12);
            int w = (int)g.MeasureString(header, hFont).Width;
            int x = (width - w) / 2;
            g.DrawString(header, hFont, Brushes.Black, x, 10);

            Font lFont = new Font("Tahoma", 9);
            int d = height - 70;
            int x0 = 30;
            int y0 = (height - d) / 2 + 10;
            int lx = 60 + d;
            int ly = y0 + (d - N * 20 + 10) / 2;
            int swe;
            Brush fBrush = Brushes.White;
            int sta = -90;
            for (int i = 0; i < N; i++)
            {
                swe = (int)(360 * p[i]);
                switch (i)
                {
                    case 0:
                        fBrush = Brushes.YellowGreen;
                        break;
                    case 1:
                        fBrush = Brushes.Gold;
                        break;
                    case 2:
                        fBrush = Brushes.Pink;
                        break;
                    case 3:
                        fBrush = Brushes.Violet;
                        break;
                    case 4:
                        fBrush = Brushes.OrangeRed;
                        break;
                    case 5:
                        fBrush = Brushes.RoyalBlue;
                        break;
                    case 6:
                        fBrush = Brushes.SteelBlue;
                        break;
                    case 7:
                        fBrush = Brushes.Chocolate;
                        break;
                    case 8:
                        fBrush = Brushes.LightGray;
                        break;
                }

                if (i == N - 1)
                    swe = 270 - sta;

                g.FillPie(fBrush, x0, y0, d, d, sta, swe);
                g.DrawPie(Pens.Black, x0, y0, d, d, sta, swe);
                g.FillRectangle(fBrush, lx, ly + i * 20, 20, 10);
                g.DrawRectangle(Pens.Black, lx, ly + i * 20, 20, 10);
                g.DrawString(title[i] + " - " + p[i].ToString("P"),
                    lFont, Brushes.Black,
                    lx + 24,
                    ly + i * 20 - 3);
                sta += swe;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form form2 = new Form2();
            form2.Paint += new PaintEventHandler(drawDiagram);
            form2.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form form2 = new Form2();
            form2.Paint += new PaintEventHandler(drawGraph);
            form2.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form form2 = new Form2();
            form2.Paint += new PaintEventHandler(drawPie);
            form2.Show();
        }
    }
}
