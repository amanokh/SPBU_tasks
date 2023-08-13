using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project7
{
    public partial class Form1 : Form
    {
        public Bitmap cannon, sky, plane;
        public Graphics g;
        public Random rnd;
        public Rectangle plnRct;
        public RectangleF bltRct;
        public int dx;
        public int dt;
        public bool isFlying;
        public bool isFire;
        public int curExpFrame;
        public Bitmap[] expFrames;
        public float curAngle;
        public float k;

        public int Xm;
        public int Ym;
        public int Xc;
        public int Yc;
        public int Xcur;
        public int Ycur;

        public int numLaser;
        public int numRocket;
        public int numDestr;
        public int numMiss;

        public int modeShoot;

        public int countdown;

        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            cannon = new Bitmap(Image.FromFile("cannon.png"), 50, 50);
            plane = new Bitmap("plane.bmp");
            plane.MakeTransparent();
            expFrames = new Bitmap[7];

            Bitmap bitmap = new Bitmap(pictureBox1.Width, pictureBox1.Height);

            rnd = new Random();

            plnRct.X = -40;
            plnRct.Y = 20 + rnd.Next(40);
            plnRct.Width = plane.Width;
            plnRct.Height = plane.Height;
            dx = 2;

            bltRct.X = pictureBox1.Width / 2;
            bltRct.Y = pictureBox1.Height;
            bltRct.Width = 6;
            bltRct.Height = 6;
            dt = 10;

            isFlying = true;
            isFire = false;

            curAngle = 0;
            Xc = pictureBox1.Width / 2;
            Yc = pictureBox1.Height;

            numLaser = 10;
            numRocket = 10;
            numDestr = 0;
            numMiss = 0;

            string resPath = Application.StartupPath + "\\";
            for (int i = 0; i < 7; i++)
            {
                expFrames[i] = new Bitmap(Image.FromFile(resPath + "tile" + i + ".png"), plane.Width, plane.Width);
            }

            countdown = 5;
            timer2.Interval = 1000;
            timer2.Enabled = false;

            timer1.Interval = 20;
            timer1.Enabled = true;
            timer1.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            if (MessageBox.Show("Пауза") == DialogResult.OK)
            {
                timer1.Start();
            }
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            curAngle = (float)Math.Atan2(e.X - pictureBox1.Width / 2, (pictureBox1.Height - e.Y));
            Xcur = e.X;
            Ycur = e.Y;
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            Xm = e.X;
            Ym = e.Y;
            if (e.Button == MouseButtons.Left)
            {
                modeShoot = 1;
                if (numLaser == 0)
                {
                    MessageBox.Show("Закончились лазеры");
                    return;
                }
                if (plnRct.Contains(e.Location))
                {
                    isFlying = false;
                }
                numLaser--;
            }
            else
            {
                if (numRocket != 0)
                {
                    modeShoot = 2;
                }
                else
                {
                    modeShoot = 3;
                }
                isFire = true;
            }
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Bitmap bitmap = new Bitmap(pictureBox1.Width, pictureBox1.Height, Graphics.FromHwnd(IntPtr.Zero));
            Graphics g2 = Graphics.FromImage(bitmap);
            g2.TranslateTransform((float)Xc, (float)Yc);
            g2.RotateTransform((float)(curAngle * 180 / Math.PI) + 45);
            g2.TranslateTransform(-(float)Xc, -(float)Yc);
            g2.DrawImage(cannon, pictureBox1.Width / 2 - cannon.Width / 2, pictureBox1.Height - cannon.Height / 2);



            if (isFlying) // полет
            {
                if (plnRct.X < pictureBox1.Width)
                {
                    plnRct.X += dx;
                }
                else
                {
                    plnRct.X = -40;
                    plnRct.Y = 20 + rnd.Next(pictureBox1.Height - 80);
                    dx = 2 + rnd.Next(4);
                    numMiss++;
                }
                g.DrawImage(plane, plnRct.X, plnRct.Y);

                if (isFire)
                {
                    Rectangle rect = new Rectangle(plnRct.X - 5, plnRct.Y - 5, plnRct.Width + 10, plnRct.Height + 10);

                    if (modeShoot == 2)
                    {
                        float length = (float)(Math.Sqrt((Xcur - Xc) * (Xcur - Xc) + (Ycur - Yc) * (Ycur - Yc)));
                        float bltLength = (float)(Math.Sqrt((bltRct.X - Xc) * (bltRct.X - Xc) + (bltRct.Y - Yc) * (bltRct.Y - Yc)));
                        if (bltLength > length)
                        {
                            bltRct.X = Xc;
                            bltRct.Y = Yc;
                            isFire = false;
                            numRocket--;

                            if (rect.Contains(new Point(Xcur, Ycur)))
                            {
                                isFlying = false;
                            }

                            if (numRocket == 0)
                                MessageBox.Show("Закончились ракеты");
                        }
                        bltRct.X -= dt;
                        bltRct.Y -= dt;
                        g2.DrawEllipse(new Pen(Brushes.Black), bltRct);
                    }
                    else
                    {
                        if (bltRct.Y < Ym)
                        {
                            bltRct.X = Xc;
                            bltRct.Y = Yc;
                            isFire = false;

                            if (rect.Contains(new Point(Xm, Ym)))
                            {
                                isFlying = false;
                            }
                        }
                        float length = (float)(Math.Sqrt((Xm - Xc) * (Xm - Xc) + (Ym - Yc) * (Ym - Yc)));
                        bltRct.X += dt * (Xm - Xc) / length;
                        bltRct.Y += dt * (Ym - Yc) / length;
                        g.DrawEllipse(new Pen(Brushes.Black), bltRct);
                    }

                }
            }
            else // взрыв
            {
                if (curExpFrame == 6)
                {
                    g.DrawImage(expFrames[curExpFrame], plnRct.X + 8, plnRct.Y - 6);

                    plnRct.X = -40;
                    plnRct.Y = 20 + rnd.Next(pictureBox1.Height - 80);
                    dx = 2 + rnd.Next(4);
                    numDestr++;

                    curExpFrame = 0;
                    isFlying = true;
                }
                else
                {
                    if (numLaser != 0 && modeShoot == 1)
                        g.DrawLine(new Pen(Brushes.DarkRed), Xc, Yc, Xm, Ym);
                    g.DrawImage(expFrames[curExpFrame++], plnRct.X + 8, plnRct.Y - 6);
                }
            }

            g.DrawImage(bitmap, 0, 0);

            g.DrawString("Лазер " + numLaser, Font, Brushes.Black, 10, pictureBox1.Height - 40);
            g.DrawString("Ракеты " + numRocket, Font, Brushes.Black, 10, pictureBox1.Height - 20);
            g.DrawString("Уничтожено " + numDestr, Font, Brushes.Black, pictureBox1.Width - 130, pictureBox1.Height - 40);
            g.DrawString("Пропущено " + numMiss, Font, Brushes.Black, pictureBox1.Width - 130, pictureBox1.Height - 20);
        }

        private void pictureBox1_MouseEnter(object sender, EventArgs e)
        {
            pictureBox1.Cursor = new Cursor("Mytarget.cur");
        }

        private void newGameToolStripMenuItem_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            pictureBox1.Visible = false;
            label1.Visible = true;
            timer2.Enabled = true;
            numLaser = 10;
            numRocket = 10;
            numDestr = 0;
            numMiss = 0;


            label1.Text = countdown.ToString();
            countdown--;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            pictureBox1.Invalidate();
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (label1.Text == "Start")
            {
                plnRct.X = -40;
                plnRct.Y = 20 + rnd.Next(pictureBox1.Height - 80);

                timer2.Enabled = false;
                pictureBox1.Visible = true;
                label1.Visible = false;
                timer1.Start();
            }
            if (countdown == 0)
            {
                label1.Text = "Start";
                return;
            }
            label1.Text = countdown.ToString();
            countdown--;
        }

    }
}
