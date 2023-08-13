using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project8
{
    public partial class BezierClockControl : ClockControl
    {
        protected override void DrawHourHand(Graphics grfx, Pen pen)
        {
            GraphicsState gs = grfx.Save();
            grfx.RotateTransform(360f * Time.Hour / 12 +
                                 30f * Time.Minute / 60);

            grfx.DrawBeziers(pen, new Point[]
            {
                new Point(0, -650), 
                new Point(0, -300),
                new Point(-100, -300),
                new Point(50, 0), 
                new Point(50, 0),
                new Point(50, 0),
                new Point(50, 0), 
                new Point(50, 75),
                new Point(-50, 75),
                new Point(-50, 0), 
                new Point(-50, 0),
                new Point(-50, 0),
                new Point(-50, 0), 
                new Point(100, -300),
                new Point(0, -300),
                new Point(0, -650), 
            });
            grfx.Restore(gs);
        }

        protected override void DrawMinuteHand(Graphics grfx, Pen pen)
        {
            GraphicsState gs = grfx.Save();
            grfx.RotateTransform(360f * Time.Minute / 60 +
                                 6f * Time.Second / 60);

            grfx.DrawBeziers(pen, new Point[]
            {
                new Point(00, -750), 
                new Point(0, -300),
                new Point(-50, -300),
                new Point(50, 0), 
                new Point(50, 0),
                new Point(50, 0),
                new Point(50, 0), 
                new Point(50, 75),
                new Point(-50, 75),
                new Point(-50, 0), 
                new Point(-50, 0),
                new Point(-50, 0),
                new Point(-50, 0), 
                new Point(50, -300),
                new Point(0, -300),
                new Point(0, -750), 
            });
            grfx.Restore(gs);
        }
    }
}

