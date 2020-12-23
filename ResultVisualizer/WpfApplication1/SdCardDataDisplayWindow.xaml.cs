using System;
using System.Windows;
using System.Windows.Media;
using System.Windows.Shapes;
using System.IO;
using System.Windows.Threading;
using System.Threading;
using MahApps.Metro.Controls;

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for SdCardDataDisplayWindow.xaml
    /// </summary>
    public partial class SdCardDataDisplayWindow : MetroWindow
    {
        private MainWindow mainWindow;
        private string FileName;
        private int NumberOfSensors = 17;
        private int counter = 0;
        public string[] Lines;
        private string FullLine;
        public SdCardDataDisplayWindow(MainWindow mainWindow)
        {
            InitializeComponent();
            this.mainWindow = mainWindow;

        }

        private void ChooseFIle_Click(object sender, RoutedEventArgs e)
        {

            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            Nullable<bool> result = dlg.ShowDialog();
            dlg.DefaultExt = ".png";

            FileName = dlg.FileName;
            Driver();

        }
        private void ChangeColor(Shape[] Rectangles, char[] sensorData)
        {
            for (int i = 0; i < NumberOfSensors; i++)
            {

                char temp = sensorData[i];
                if (temp == '1')
                {

                    Rectangles[i].Fill = new SolidColorBrush(Colors.Green);
                    Rectangles[i].Refresh();
                    Rectangles[i].UpdateLayout();
                }
                else
                {
                    Rectangles[i].Fill = new SolidColorBrush(Colors.Red);
                    Rectangles[i].Refresh();
                    Rectangles[i].UpdateLayout();
                }
            }
        }
       
        private void IntroduceDelay()
        {
            Thread.Sleep(1000);

            counter += 1;
        }
        private void Driver()
        {

            FileStream fs = new FileStream(FileName, FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs);
            while((FullLine= sr.ReadLine())!=null)
            {

                Lines = FullLine.Split(',');
            }
            char[] IndividualSensorData = null;
            Shape[] Rectangles = { R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17 };

            while (counter < Lines.Length)
            {

                if (Lines[counter] == "00000000000000000")
                {
                    counter = counter + 1;
                    continue;

                }
                else 
                {
                    IndividualSensorData = Lines[counter].ToCharArray();

                    ChangeColor(Rectangles, IndividualSensorData);

                    IntroduceDelay();
                }
                
            }
            fs.Close();

        }
        private void StartDisplay_Click(object sender, RoutedEventArgs e)
        {
            
            Driver();

        }
        private void Window_Closed(object sender, EventArgs e)
        {
            mainWindow.Show();
        }
    }

    public static class ExtensionMethods
    {
        private static Action EmptyDelegate = delegate () { };


        public static void Refresh(this UIElement uiElement)

        {
            uiElement.Dispatcher.Invoke(DispatcherPriority.Render, EmptyDelegate);
        }
    }
}
