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
        private int[] tries = new int[128];
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
            tries = new int[128];
            curr = 0;
            amount = 0;
            enableTiles(true);
        }

        private void tile_Click(object sender, EventArgs eventArgs)
        {
            if (sender is CharButton && text != null)
            {
                amount++;
                CharButton s = (CharButton) sender;
                bool correct = letterEntered(s.Text);
                if (!correct)
                {
                    s.Enabled = false;
                }
            }
            else
            {
                MessageBox.Show("Слово не получено");
            }
        }

        private void a_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            e.Handled = true;
            string chr = e.KeyChar.ToString();
            if (alphabet.Contains(chr)) {
                bool correct = letterEntered(chr);

                if (!correct)
                {
                    atile[alphabet.IndexOf(chr)].Enabled = false;
                }
            }
        }

        private bool letterEntered(string letter) {
            if (letter != text[curr].ToString())
            {
                label3.Text = "Неверно";
                ++tries[curr];
                return false;
            }
            else
            {

                enableTiles(true);
                double res = 0;
                if (curr != n - 1) curr++;
                else
                {
                    int sum = tries.Sum();
                    double p;

                    for (int i = 0; i < n; ++i)
                    {
                        int t = tries[i];
                        if (t != 33)
                        {
                            p = (33 - t) / 33.0;
                            res += -p * Math.Log(p, 2);
                        }
                    }

                    label4.Text = res.ToString(CultureInfo.InvariantCulture);
                    enableTiles(false);
                }

                textBox1.Text += letter;
                label3.Text = "Верно";
                return true;
            }
        }

        private void enableTiles(bool f)
        {
            foreach (var t in atile) t.Enabled = f;
            Invalidate();
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
