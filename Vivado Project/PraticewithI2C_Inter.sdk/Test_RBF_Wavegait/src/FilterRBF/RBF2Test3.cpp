//
// File: RBF2Test3.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 18-May-2018 14:33:38
//

// Include Files
#include "rt_nonfinite.h"
#include "MvAvgFilter3.h"
#include "RBF2Test3.h"

// Function Definitions

//
// Arguments    : const double data_TE[18]
// Return Type  : double
//
double RBF2Test3(const double data_TE[18])
{
  double WalkControls;
  double y;
  int j;
  double d0;
  int i1;
  static const double a[18] = { 1.09035951325095, 0.429769426184547,
    -0.458420091768886, 0.125181506447754, 0.717794916711768, -0.303326578447395,
    0.496516496193718, 0.94590730519312, 0.59428329551604, 0.117755021516496,
    0.360322001434607, -0.397922299794806, -1.51402374844417, -1.40511443666366,
    2.62433875758742, -0.934203965516472, -0.621879386918041, -1.25897167469552
  };

  static const double dv0[18] = { 0.0369729578788622, 0.0415684974792259,
    0.397086490380301, 0.0465855680314271, 0.0339049655024296,
    0.0383844215607752, 0.0364288125499674, 0.0364982174528618,
    0.0353975081616068, 0.00321328081358969, 0.0475780861637404,
    0.0485253175112575, 0.0982964851214834, 0.10134876555206, 0.115126294367555,
    0.0490754645725612, 0.0368327910338462, 0.0869997407183745 };

  static const double c[324] = { 0.179578582278481, 0.139921113924051,
    0.098667329113924, 0.15354446835443, 0.138312582278481, 0.154138291139241,
    0.180432341772152, 0.111201848101266, 0.0804533924050633, 0.173577341772152,
    0.0852790886075949, 0.0717423670886076, 0.143459873417721,
    0.0945840253164556, 0.10945717721519, 0.19174182278481, 0.090773,
    0.101500962025317, 0.166969759493671, 0.110966772151899, 0.0966381139240506,
    0.15622946835443, 0.118428126582278, 0.150352012658228, 0.152962936708861,
    0.109704658227848, 0.0869866835443038, 0.179751784810126, 0.105373949367089,
    0.080837, 0.130826455696203, 0.102292886075949, 0.0998552278481013,
    0.195973594936709, 0.0923196835443038, 0.104247886075949, 0.063539, 0.063539,
    0.0, 0.125122, 0.094819, 0.062561, 0.0, 0.294233, 0.156403, 0.0, 0.218964,
    0.063539, 0.0, 0.187683, 0.063539, 0.062561, 0.093842, 0.063539, 0.158531,
    0.112464, 0.0905874050632911, 0.146837810126582, 0.113466278481013,
    0.112018481012658, 0.182214215189873, 0.109135506329114, 0.103864329113924,
    0.138918797468354, 0.0963287594936709, 0.069218164556962, 0.148025772151899,
    0.102404240506329, 0.11660917721519, 0.182461620253165, 0.0953759873417722,
    0.0828539746835443, 0.176250088607595, 0.113206443037975, 0.0933591139240506,
    0.140725278481013, 0.127163911392405, 0.130566556962025, 0.208916455696203,
    0.0935694936708861, 0.0916143924050633, 0.14895382278481, 0.107898101265823,
    0.0772733797468355, 0.152752481012658, 0.0909586329113924, 0.129601455696203,
    0.208471012658228, 0.10336935443038, 0.0708267721518987, 0.167749405063291,
    0.108937443037975, 0.0984446075949367, 0.139116784810127, 0.140354215189873,
    0.12986129113924, 0.181372746835443, 0.110843075949367, 0.0894242784810126,
    0.15443529113924, 0.103357025316456, 0.0696264936708861, 0.134253936708861,
    0.108974544303798, 0.115643924050633, 0.17606446835443, 0.100684278481013,
    0.0762586962025316, 0.161587291139241, 0.118415708860759, 0.0895108481012658,
    0.154002278481013, 0.110137683544304, 0.097949658227848, 0.176745012658228,
    0.121026582278481, 0.0959575569620253, 0.138943481012658, 0.0888922531645569,
    0.0813319873417722, 0.151960620253165, 0.0999046582278481, 0.101414303797468,
    0.173787708860759, 0.0930621518987342, 0.0984322278481013, 0.155054,
    0.111474151898734, 0.0990385569620253, 0.155833556962025, 0.0956357974683544,
    0.106239987341772, 0.164903455696202, 0.105175962025316, 0.100585278481013,
    0.158357772151899, 0.11261246835443, 0.0698120886075949, 0.151774987341772,
    0.122919683544304, 0.11887346835443, 0.186012873417722, 0.104371632911392,
    0.096625670886076, 0.164891088607595, 0.11824246835443, 0.0962544556962025,
    0.126186341772152, 0.114542683544304, 0.113206417721519, 0.194736265822785,
    0.104903746835443, 0.10341882278481, 0.171783189873418, 0.111907126582278,
    0.0689335443037975, 0.155029265822785, 0.112513443037975, 0.123142405063291,
    0.16345570886076, 0.0835715189873418, 0.0852914303797468, 0.156675012658228,
    0.12003664556962, 0.0969473797468354, 0.128760063291139, 0.116695696202532,
    0.114802632911392, 0.196146860759494, 0.106586556962025, 0.102020607594937,
    0.174592, 0.111399797468354, 0.0698244303797469, 0.157466873417722,
    0.114406607594937, 0.125332544303797, 0.160659265822785, 0.0849573670886076,
    0.0841035696202532, 0.139896303797468, 0.103926189873418, 0.082383658227848,
    0.181397556962025, 0.133622898734177, 0.137285392405063, 0.20740682278481,
    0.138275392405063, 0.170521088607595, 0.195701417721519, 0.12287017721519,
    0.100832810126582, 0.21217082278481, 0.124268379746835, 0.108516759493671,
    0.175136443037975, 0.0935075696202532, 0.066879506329114, 0.140453075949367,
    0.126087316455696, 0.0873702405063292, 0.16871453164557, 0.136580151898734,
    0.121026481012658, 0.222849151898734, 0.125703772151899, 0.140663481012658,
    0.199896037974684, 0.102379443037975, 0.0843634683544304, 0.173169063291139,
    0.112637164556962, 0.0977022151898735, 0.191766620253165, 0.114109721518987,
    0.0985436582278481, 0.186891316455696, 0.121781316455696, 0.0886322784810127,
    0.170261303797468, 0.156922518987342, 0.119752025316456, 0.207221278481013,
    0.137941341772152, 0.0873578734177216, 0.178440202531646, 0.0842026455696203,
    0.081171, 0.183599949367089, 0.112006126582278, 0.10301046835443,
    0.198596797468354, 0.108776632911392, 0.153482430379747, 0.185035329113924,
    0.106301924050633, 0.0747862531645569, 0.163010253164557, 0.122956772151899,
    0.107390797468354, 0.198881443037975, 0.153841405063291, 0.173738189873418,
    0.166610962025317, 0.14411570886076, 0.103542594936709, 0.202247126582278,
    0.126112063291139, 0.0955863670886076, 0.156105835443038, 0.0959327341772152,
    0.0793768734177215, 0.154769443037975, 0.117883594936709, 0.100993594936709,
    0.13440246835443, 0.117190759493671, 0.122907265822785, 0.200848835443038,
    0.123216658227848, 0.0866401518987341, 0.154237316455696, 0.0916143417721519,
    0.0613608987341772, 0.141727569620253, 0.0985560506329114,
    0.0922083670886076, 0.182572974683544, 0.0967618607594937,
    0.0915896582278482, 0.179924962025317, 0.130987253164557, 0.102156683544304,
    0.173070088607595, 0.111474088607595, 0.101698898734177, 0.189935278481013,
    0.101129759493671, 0.0911566075949367, 0.182498759493671, 0.0858482784810127,
    0.0747862405063291, 0.179974493670886, 0.108083670886076, 0.0923568354430379,
    0.191271632911392, 0.0828415063291139, 0.117029810126582, 0.203620481012658,
    0.127485518987342, 0.113676607594937, 0.195367341772152, 0.118576544303797,
    0.104223063291139, 0.206491227848101, 0.101203936708861, 0.0952275063291139,
    0.157083265822785, 0.0941633417721519, 0.0647141392405063, 0.192286240506329,
    0.0963287341772152, 0.0953017594936708, 0.185715873417722, 0.10690817721519,
    0.0797976075949367, 0.180964405063291, 0.13121, 0.112785658227848,
    0.184639367088608, 0.120358405063291, 0.127423683544304, 0.223146063291139,
    0.151490405063291, 0.110595518987342, 0.195218886075949, 0.120927569620253,
    0.0999047594936709, 0.157108037974683, 0.14178946835443, 0.169617797468355,
    0.191840911392405, 0.115458392405063, 0.0873702025316456 };

  // 'RBF2Test3:4' c = [0.179578582278481,0.166969759493671,0.0635390000000000,0.158531000000000,0.176250088607595,0.167749405063291,0.161587291139241,0.155054000000000,0.164891088607595,0.156675012658228,0.139896303797468,0.140453075949367,0.186891316455696,0.185035329113924,0.154769443037975,0.179924962025317,0.203620481012658,0.180964405063291;0.139921113924051,0.110966772151899,0.0635390000000000,0.112464000000000,0.113206443037975,0.108937443037975,0.118415708860759,0.111474151898734,0.118242468354430,0.120036645569620,0.103926189873418,0.126087316455696,0.121781316455696,0.106301924050633,0.117883594936709,0.130987253164557,0.127485518987342,0.131210000000000;0.0986673291139240,0.0966381139240506,0,0.0905874050632911,0.0933591139240506,0.0984446075949367,0.0895108481012658,0.0990385569620253,0.0962544556962025,0.0969473797468354,0.0823836582278480,0.0873702405063292,0.0886322784810127,0.0747862531645569,0.100993594936709,0.102156683544304,0.113676607594937,0.112785658227848;0.153544468354430,0.156229468354430,0.125122000000000,0.146837810126582,0.140725278481013,0.139116784810127,0.154002278481013,0.155833556962025,0.126186341772152,0.128760063291139,0.181397556962025,0.168714531645570,0.170261303797468,0.163010253164557,0.134402468354430,0.173070088607595,0.195367341772152,0.184639367088608;0.138312582278481,0.118428126582278,0.0948190000000000,0.113466278481013,0.127163911392405,0.140354215189873,0.110137683544304,0.0956357974683544,0.114542683544304,0.116695696202532,0.133622898734177,0.136580151898734,0.156922518987342,0.122956772151899,0.117190759493671,0.111474088607595,0.118576544303797,0.120358405063291;0.154138291139241,0.150352012658228,0.0625610000000000,0.112018481012658,0.130566556962025,0.129861291139240,0.0979496582278480,0.106239987341772,0.113206417721519,0.114802632911392,0.137285392405063,0.121026481012658,0.119752025316456,0.107390797468354,0.122907265822785,0.101698898734177,0.104223063291139,0.127423683544304;0.180432341772152,0.152962936708861,0,0.182214215189873,0.208916455696203,0.181372746835443,0.176745012658228,0.164903455696202,0.194736265822785,0.196146860759494,0.207406822784810,0.222849151898734,0.207221278481013,0.198881443037975,0.200848835443038,0.189935278481013,0.206491227848101,0.223146063291139;0.111201848101266,0.109704658227848,0.294233000000000,0.109135506329114,0.0935694936708861,0.110843075949367,0.121026582278481,0.105175962025316,0.104903746835443,0.106586556962025,0.138275392405063,0.125703772151899,0.137941341772152,0.153841405063291,0.123216658227848,0.101129759493671,0.101203936708861,0.151490405063291;0.0804533924050633,0.0869866835443038,0.156403000000000,0.103864329113924,0.0916143924050633,0.0894242784810126,0.0959575569620253,0.100585278481013,0.103418822784810,0.102020607594937,0.170521088607595,0.140663481012658,0.0873578734177216,0.173738189873418,0.0866401518987341,0.0911566075949367,0.0952275063291139,0.110595518987342;0.173577341772152,0.179751784810126,0,0.138918797468354,0.148953822784810,0.154435291139240,0.138943481012658,0.158357772151899,0.171783189873418,0.174592000000000,0.195701417721519,0.199896037974684,0.178440202531646,0.166610962025317,0.154237316455696,0.182498759493671,0.157083265822785,0.195218886075949;0.0852790886075949,0.105373949367089,0.218964000000000,0.0963287594936709,0.107898101265823,0.103357025316456,0.0888922531645569,0.112612468354430,0.111907126582278,0.111399797468354,0.122870177215190,0.102379443037975,0.0842026455696203,0.144115708860760,0.0916143417721519,0.0858482784810127,0.0941633417721519,0.120927569620253;0.0717423670886076,0.0808370000000000,0.0635390000000000,0.0692181645569620,0.0772733797468355,0.0696264936708861,0.0813319873417722,0.0698120886075949,0.0689335443037975,0.0698244303797469,0.100832810126582,0.0843634683544304,0.0811710000000000,0.103542594936709,0.0613608987341772,0.0747862405063291,0.0647141392405063,0.0999047594936709;0.143459873417721,0.130826455696203,0,0.148025772151899,0.152752481012658,0.134253936708861,0.151960620253165,0.151774987341772,0.155029265822785,0.157466873417722,0.212170822784810,0.173169063291139,0.183599949367089,0.202247126582278,0.141727569620253,0.179974493670886,0.192286240506329,0.157108037974683;0.0945840253164556,0.102292886075949,0.187683000000000,0.102404240506329,0.0909586329113924,0.108974544303798,0.0999046582278481,0.122919683544304,0.112513443037975,0.114406607594937,0.124268379746835,0.112637164556962,0.112006126582278,0.126112063291139,0.0985560506329114,0.108083670886076,0.0963287341772152,0.141789468354430;0.109457177215190,0.0998552278481013,0.0635390000000000,0.116609177215190,0.129601455696203,0.115643924050633,0.101414303797468,0.118873468354430,0.123142405063291,0.125332544303797,0.108516759493671,0.0977022151898735,0.103010468354430,0.0955863670886076,0.0922083670886076,0.0923568354430379,0.0953017594936708,0.169617797468355;0.191741822784810,0.195973594936709,0.0625610000000000,0.182461620253165,0.208471012658228,0.176064468354430,0.173787708860759,0.186012873417722,0.163455708860760,0.160659265822785,0.175136443037975,0.191766620253165,0.198596797468354,0.156105835443038,0.182572974683544,0.191271632911392,0.185715873417722,0.191840911392405;0.0907730000000000,0.0923196835443038,0.0938420000000000,0.0953759873417722,0.103369354430380,0.100684278481013,0.0930621518987342,0.104371632911392,0.0835715189873418,0.0849573670886076,0.0935075696202532,0.114109721518987,0.108776632911392,0.0959327341772152,0.0967618607594937,0.0828415063291139,0.106908177215190,0.115458392405063;0.101500962025317,0.104247886075949,0.0635390000000000,0.0828539746835443,0.0708267721518987,0.0762586962025316,0.0984322278481013,0.0966256708860760,0.0852914303797468,0.0841035696202532,0.0668795063291140,0.0985436582278481,0.153482430379747,0.0793768734177215,0.0915896582278482,0.117029810126582,0.0797976075949367,0.0873702025316456]; 
  // 'RBF2Test3:5' w = [1.09035951325095,0.429769426184547,-0.458420091768886,0.125181506447754,0.717794916711768,-0.303326578447395,0.496516496193718,0.945907305193120,0.594283295516040,0.117755021516496,0.360322001434607,-0.397922299794806,-1.51402374844417,-1.40511443666366,2.62433875758742,-0.934203965516472,-0.621879386918041,-1.25897167469552]; 
  // 'RBF2Test3:6' spread = [0.0369729578788622,0.0415684974792259,0.397086490380301,0.0465855680314271,0.0339049655024296,0.0383844215607752,0.0364288125499674,0.0364982174528618,0.0353975081616068,0.00321328081358969,0.0475780861637404,0.0485253175112575,0.0982964851214834,0.101348765552060,0.115126294367555,0.0490754645725612,0.0368327910338462,0.0869997407183745]; 
  // 'RBF2Test3:7' num_in = 18;
  //  Select 18(Torque) + 3 (Gyro)
  // 'RBF2Test3:8' g = zeros(num_in,1);
  // 'RBF2Test3:10' x = data_TE(1:num_in,1);
  // 'RBF2Test3:11' for j = 1:num_in
  // 'RBF2Test3:14' WalkControls = mysign(w*g);
  y = 0.0;
  for (j = 0; j < 18; j++) {
    // 'RBF2Test3:12' g(j,:) = exp(-(x-c(:,j))'*(x-c(:,j))/(2*spread(j)^2));
    d0 = 0.0;
    for (i1 = 0; i1 < 18; i1++) {
      d0 += -(data_TE[i1] - c[i1 + 18 * j]) * (data_TE[i1] - c[i1 + 18 * j]);
    }

    y += a[j] * std::exp(d0 / (2.0 * (dv0[j] * dv0[j])));
  }

  //  a signsum function
  // 'mysign:4' out = 1*(d>=0) + (-1)*(d<0);
  WalkControls = (y >= 0.0) - (y < 0.0);

  //  if distance(d,1) <= distance(d,0),
  //      out = 1;
  //  else
  //      out = 0;
  //  end
  return WalkControls;
}

//
// File trailer for RBF2Test3.cpp
//
// [EOF]
//
