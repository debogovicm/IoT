import {
    Chart as ChartJS,
    CategoryScale,
    LinearScale,
    PointElement,
    LineElement,
    Title,
    Tooltip,
    Legend,
  } from 'chart.js';
  import { Line } from 'react-chartjs-2';
  
  ChartJS.register(
    CategoryScale,
    LinearScale,
    PointElement,
    LineElement,
    Title,
    Tooltip
  );
  
  export default function Graph(data, title, label, min, max, flag=false) {
      const options = {
        responsive: true,
        plugins: {
          title: {
            display: true,
            text: title,
          }
        },
        scales: {
          y: {
            suggestedMin: min,
            suggestedMax: max,
            ticks: {
              callback: (val, index) => {
                if (flag) {
                  const winds = {
                    0: '',
                    1: 'N',
                    2: 'NE',
                    3: 'E',
                    4: 'SE',
                    5: 'S',
                    6: 'SW',
                    7: 'W',
                    8: 'NW' 
                  }
                  return winds[val]
                }
                return val
              }
            }
          }
        }
      }
  
      const labels = ['1', '2', '3', '4', '5'];
  
      const graphData = {
        labels,
        datasets: [{
            label: label,
            data: data,
            borderColor: 'rgb(255, 99, 132)',
            backgroundColor: 'rgba(255, 99, 132, 0.5)',
          }]
      };
  
      return <div>
          <Line options={options} data={graphData} />
      </div>
      
      
  }