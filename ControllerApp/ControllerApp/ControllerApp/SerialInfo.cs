using System;
using System.IO.Ports;
namespace ControllerApp
{
    public class SerialInfo
    {

        public static void GetPorts()
        {
            Console.WriteLine("Serial ports available:");
            Console.WriteLine("-----------------------");
            foreach (var portName in SerialPort.GetPortNames())
            {
                Console.WriteLine(portName);
            }
        }

    }
}
