using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace les9_2
{
    public partial class Form1 : Form
    {
        private static readonly string path = Directory.GetCurrentDirectory();
        private static readonly int nRows = 4;
        private static readonly int nCols = 10;
        private readonly Control[] atile = new Control[33];
        private readonly string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
        private int curr;
        private static int n;
        private readonly string text = File.ReadAllText(path + "\\text.txt", Encoding.UTF8);
        private int[] tries = new int[33];
        private int amount;
        public Form1()
        {
            InitializeComponent();
            var grfx = CreateGraphics();
            var sizeTile = new Size((int)(2 * grfx.DpiX / 3),
                (int)(2 * grfx.DpiY / 3));

            for (var iRow = 0; iRow < nRows; iRow++)
                for (var iCol = 0; iCol < nCols; iCol++)
                {
                    var iNum = iRow * nCols + iCol + 1;

                    if (iNum == nRows * nCols)
                        continue;

                    if (iNum > 33) break;

                    var tile = new CharButton(iNum - 1, alphabet[iNum - 1].ToString());
                    tile.Parent = this;
                    tile.Location = new Point(iCol * sizeTile.Width,
                        200 + iRow * sizeTile.Height);
                    tile.Size = new Size(new Point(sizeTile));
                    
                    tile.Click += tile_Click;

                    atile[iNum - 1] = tile;
                }

            n = text.Length;
            tries = new int[33];
            curr = 0;
            label4.Text = text;
            amount = 0;
            enableTiles(true);
        }

        private void tile_Click(object sender, EventArgs eventArgs)
        {
            if (sender is CharButton s && text != null)
            {
                amount++;
                if (s.Text != text[curr].ToString())
                {
                    label3.Text = "Не угадали";
                    s.Enabled = false;
                }
                else
                {
                    ++tries[amount];
                    amount = 0;
                    enableTiles(true);
                    double res = 0;
                    if (curr != n - 1) curr++;
                    else
                    {
                        int sum = tries.Sum();
                        double p;

                        foreach (var t in tries)
                        {
                            if (t != 0)
                            {
                                p = t / (double)sum;
                                res += -p * Math.Log(p,2);
                            }
                        }

                        label4.Text = res.ToString(CultureInfo.InvariantCulture);
                        enableTiles(false);
                    }

                    textBox1.Text += s.Text;
                    label3.Text = "Угадали";
                }
            }
            else
            {
                MessageBox.Show("Слово не получено");
            }
        }

        private void enableTiles(bool f)
        {
            foreach (var t in atile) t.Enabled = f;
        }

        public static bool IsAllLetters(string s)
        {
            foreach (var c in s)
                if (!char.IsLetter(c))
                    return false;

            return true;
        }
    }
}
