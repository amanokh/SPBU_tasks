using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project6
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            label3.Enabled = numericUpDown3.Enabled = checkBox1.Checked;
            numericUpDown3.Value = numericUpDown3.Enabled ? 10 : 0;
        }
    }
}
