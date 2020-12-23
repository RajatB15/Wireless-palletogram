using System.Windows;
using System.Windows.Controls;
using System.IO;
using System.Windows.Shapes;
using System.Windows.Media;
using System.Threading;
using System.Threading.Tasks;
using System;
using System.Timers;

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for DisplayInBoxes.xaml
    /// </summary>
    public partial class DisplayInBoxes : Page
    {

        private int NumberOfSensors = 17;
        private int counter = 0;
        private int DataLength = 0;
        private static System.Timers.Timer _delayTimer;

        public DisplayInBoxes()
        {
            InitializeComponent();
        }

        private void ChangeColor(Shape[] Rectangles, char[] sensorData) {
            for (int i = 0; i < NumberOfSensors; i++)
            {

                char temp = sensorData[i];
                if (temp == '1')
                {

                    Rectangles[i].Fill = new SolidColorBrush(Colors.Green);

                }
                else
                {
                    Rectangles[i].Fill = new SolidColorBrush(Colors.Red);
                }
            }
        }
        private static void delay(int Time_delay)
        {
            int i = 0;
            //  ameTir = new System.Timers.Timer();
            _delayTimer = new System.Timers.Timer();
            _delayTimer.Interval = Time_delay;
            _delayTimer.AutoReset = false; //so that it only calls the method once
            _delayTimer.Elapsed += (s, args) => i = 1;
            _delayTimer.Start();
            while (i == 0) { };
        }
        private void IntroduceDelay() {

            delay(3000);
            if (counter >= DataLength) {
                DataLength = 0;
                counter = 0;
                return;
            }

            Driver();
        }

        private void Driver() {
        
            FileStream fs = new FileStream("C:/Users/Z0041DYB/Desktop/testwpf2.csv", FileMode.Open, FileAccess.Read);
            using (StreamReader sr = new StreamReader(fs))
            {

                string[] Line = sr.ReadLine().Split(',');
                if (counter >= DataLength)
                {
                    return;
                }
                char[] IndividualSensorData = null;
                Shape[] Rectangles = { R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17 };

                IndividualSensorData = Line[counter].ToCharArray();
                
                ChangeColor(Rectangles, IndividualSensorData);
                counter += 1;
                
            }
            
            
        }
        private void StartDisplay_Click(object sender, RoutedEventArgs e)
        {
            FileStream fs = new FileStream("C:/Users/Z0041DYB/Desktop/testwpf2.csv", FileMode.Open, FileAccess.Read);
            using (StreamReader sr = new StreamReader(fs))
            {
                string[] Line = sr.ReadLine().Split(',');
                DataLength = Line.Length;

            }
            Driver();
            //IntroduceDelay();

        }

        private void Page_Loaded(object sender, RoutedEventArgs e)
        {

        }
        
    }
}
